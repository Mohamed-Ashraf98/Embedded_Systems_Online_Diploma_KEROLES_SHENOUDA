/*
 ============================================================================
 Name        : ex1_how_to_handle_pointers.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Demonstrate how to handle the pointers in the program, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int var = 0;
	int *ptr = &var;

	var = 29;
	printf("The value of var = %d\n",var);
	printf("The address of var is 0x%p\n",&var);

	printf("\n");

	*ptr = 34;
	printf("The value of var = %d\n",*ptr);
	printf("The address of var is 0x%p\n",ptr);

	return 0;
}
