//file: person_info.c
#include <stdio.h>
#include "person_info.h"

void print_person_info(char *name, person_info *info)
{
	printf("name: %s, age: %d, gender: %s\n",
			name, info->age, info->gender);
}

int main(int argc, char *argv[])
{
	char *name = "handsome";
	person_info info;
	info.age = 18;
	info.gender = "male";

	print_person_info(name, &info);
}
