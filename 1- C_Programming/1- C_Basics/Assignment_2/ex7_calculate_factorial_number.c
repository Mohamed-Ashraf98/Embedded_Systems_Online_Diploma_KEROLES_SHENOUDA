/*
 ============================================================================
 Name        : ex7_calculate_factorial_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Finding the factorial number of any +ve integer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int var , count , mul = 1 ;

	printf("Enter a positive integer to calculate it's factorial :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&var);

	if(var > 1)
	{
		for(count = 1;count <= var;count++)
		{
			mul *= count ;
		}
		printf("Factorial of %d is %d",var,mul);
	}
	else if(var == 0)
	{
		printf("Factorial of %d is 1",var);
	}
	else
	{
		printf("Error!! Factorial of -ve integer doesn't exist.");
	}
	return 0;
}
