/*filename: hello_world.c */
#include <stdio.h>
#include "hello_world.h"


void print_hello_world()
{
	printf("hello world...");
}


int main(int arch, char *argv[])
{
	print_hello_world();

	return (0);
}
