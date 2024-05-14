#include <stdio.h>
#include <stdlib.h>

void function_3(void)
{
    printf("function_3\n");
    int* p = NULL;
    *p = 123;
    printf("value: %d\n", *p);
}

/* "static" means don't export the symbol... */
static void function_2(void)
{
    printf("function_2\n");
    function_3();
}

void function_1(void)
{
    printf("function_1\n");
    function_2();
}

int main(int argc, char const *argv[])
{
    function_1();
    return 0;
}
