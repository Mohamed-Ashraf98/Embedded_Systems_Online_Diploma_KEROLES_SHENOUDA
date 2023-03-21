/*
 ============================================================================
 Name        : ex5_fine_ASCII_of_char.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x ;
	printf("Enter the character you want to find its ASCII value : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);

	printf("The ASCII value %c is :  %d",x,x);

	return 0;
}
