/*
 ============================================================================
 Name        : ex4_multiply_two_floats.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Multiply two Floating Point Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x,y ;
	printf("Enter the two float numbers : \n");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&x,&y);

	printf("The sum of two integers you entered :  %f", (x*y) );

	return 0;
}
