/*
 ============================================================================
 Name        : ex2_calculate_factorial_of_number_using_recursion.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate the factorial number entered by the user using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int factorial(int var);

int main()
{
	int num , fact ;

	printf("Enter a positive integer you want to calculate its Factorial :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	if(num<0)
		printf("Error!!! There is no factorial of a negative integer");
	else if(num == 0)
		printf("The factorial of zero is 1");
	else
	{
		fact = factorial(num);
		printf("The factorial of %d is %d",num,fact);
	}

	return 0;
}

int factorial(int var)
{
	if(var == 1)
		return 1;
	else
		return var*factorial(var-1);
}
