/*
 ============================================================================
 Name        : ex4_check_number_positive_or_negative.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Enter a number and check if it's +ve or -ve, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float var ;

	printf("Enter the number you want to check : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var);

	if(var > 0)
	{
		printf("%.3f is a positive number.",var);
	}
	else if(var < 0)
	{
		printf("%.3f is a negative number.",var);
	}
	else
	{
		printf("you entered zero.");
	}
	return 0;
}
