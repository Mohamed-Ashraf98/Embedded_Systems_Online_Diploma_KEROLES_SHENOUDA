/*
 ============================================================================
 Name        : ex3_find_largest_number_out_of_3.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : enter 3 numbers and find the largest one, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float var_1,var_2,var_3 ;

	printf("Enter the first number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var_1);

	printf("Enter the second number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var_2);

	printf("Enter the third number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var_3);

	if(var_1 > var_2)
	{
		if(var_1 > var_3)
		{
			printf("The largest number is :  %.3f",var_1);
		}
		else
		{
			printf("The largest number is :  %.3f",var_3);
		}
	}
	else
	{
		if(var_2 > var_3)
		{
			printf("The largest number is :  %.3f",var_2);
		}
		else
		{
			printf("The largest number is :  %.3f",var_3);
		}
	}

	return 0;
}
