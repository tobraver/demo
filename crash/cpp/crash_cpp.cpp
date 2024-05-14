#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // stderror
#include <signal.h> // signal
#include <execinfo.h> // backtrace, backtrace_symbols, backtrace_symbols_fd
#include <dlfcn.h> // dladdr
#include <cxxabi.h> // abi::__cxa_demangle

void signal_handler(int signum);
void crash_trace_dump(int signum);

void function_3(int* value)
{
    printf("function_3\n");
	*value = 10;
    printf("content: %d\n", *value);
}

void function_3(void)
{
    printf("function_3\n");
    int* p = NULL;
    // *p = 123;
    printf("value: %d\n", *p);
}

/* "static" means don't export the symbol... */
static void function_2(void)
{
    printf("function_2\n");
    // function_3();
	function_3(NULL);
}

void function_1(void)
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
	if (strings) {
		for (size_t i = 1; i < size; i++) {

            char fname[1024];
			Dl_info info;
            snprintf(fname, 1024, "%s", strings[i]);

			if (dladdr(bt_buffer[i], &info) && info.dli_sname) {

				if (info.dli_sname[0] == '_') {
					int status = 0;
					char *demangled = abi::__cxa_demangle(info.dli_sname, nullptr, nullptr, &status);

					if (status == 0 && demangled) {
                        snprintf(fname, 1024, "%s", demangled);
					}

					if (demangled) {
						free(demangled);
					}
				}
			}
            printf("[%lu] %s\n", i, fname);
		}

		free(strings);
	}
	printf("================================================================\n");
}