#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // stderror
#include <signal.h> // signal
#include <execinfo.h> // backtrace, backtrace_symbols, backtrace_symbols_fd

void signal_handler(int signum);
void crash_trace_dump(int signum);

void function_3(void)
{
    printf("function_3\n");
    int* p = NULL;
    // *p = 123;
    printf("value: %d\n", *p);
}

static void function_2(void)
{
    printf("function_2\n");
    function_3();
}

static void function_1(void)
{
    printf("function_1\n");
    function_2();
}

int main(int argc, char const *argv[])
{
    signal(SIGSEGV, signal_handler);
    signal(SIGABRT, signal_handler);

    function_1();

    return 0;
}

void signal_handler(int signum)
{
    crash_trace_dump(signum);

    signal(signum, SIG_DFL); // recover signal
    raise(signum);
}

void crash_trace_dump(int signum)
{
    void *bt_buffer[256];
	size_t size = backtrace(bt_buffer, 256);

	// Dump the backtrace to stderr with a message to the user
	printf("================================================================\n");

	char **strings = backtrace_symbols(bt_buffer, size);
	if (strings) 
    {
        for(size_t i = 0; i < size; i++ )
        {
		    printf("[%ld]: %s\n", i, strings[i]);
        }
		free(strings);
	}
	printf("================================================================\n");
}