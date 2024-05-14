/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

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


extern "C" void app_main(void)
{
    function_1();
}
