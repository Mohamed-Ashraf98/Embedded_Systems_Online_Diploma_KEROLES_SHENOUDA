/*
 ============================================================================
 Name        : ex6_calculate_sum_of_natural_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Enter a positive integer and calculate sum of it's natural, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int var, count , sum = 0 ;

	printf("Enter a positive integer to calculate it's sum of natural numbers :  ");
	fflush(stdin);fflush(stdout);
	scanf("%u",&var);

	for(count = 1;count <= var;count++)
	{
		sum += count ;
	}

	printf("sum of its natural number =  %u",sum);

	return 0;
}
