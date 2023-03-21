/*
 ============================================================================
 Name        : ex7_swapping_two_numbers_without_temp_variable.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : swapping two numbers without the need of temp variable, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float var1,var2 ;
	printf("Enter the fisrt number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var1);

	printf("Enter the second number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var2);

	var1 = var1+var2 ;
	var2 = var1-var2 ;
	var1 = var1-var2 ;

	printf("After swapping, the value of the first number is :  %.2f\n",var1);
	printf("After swapping, the value of the second number is :  %.2f",var2);

	return 0;
}
