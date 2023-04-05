/*
 ============================================================================
 Name        : ex4_calculate_power_of_number_using_Recursion.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate power of a number entered by the user using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int calc_power(int base,int pow);

int main()
{
	int num , power ;

	printf("Enter the base number you want to calculate its power :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("Enter the power number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&power);

	if(power < 0)
		printf("Please Enter a positive integer for the power number.");
	else
		printf("%d ^ %d = %d",num,power, calc_power(num,power) );

	return 0;
}

int calc_power(int base,int pow)
{
	if(pow == 0)
		return 1;
	else
		return base * calc_power(base,pow-1) ;
}
