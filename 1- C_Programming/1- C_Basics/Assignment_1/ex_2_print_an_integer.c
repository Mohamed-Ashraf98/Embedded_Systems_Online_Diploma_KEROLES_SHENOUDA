/*
 ============================================================================
 Name        : ex_2_print_an_integer.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Print a Integer Entered by a User, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;

	printf("Enter an integer :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	printf("You entered :  %d",x);

	return 0;
}
