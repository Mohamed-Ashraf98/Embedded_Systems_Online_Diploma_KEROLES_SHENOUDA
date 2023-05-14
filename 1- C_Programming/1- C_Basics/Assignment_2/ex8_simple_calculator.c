/*
 ============================================================================
 Name        : ex8_simple_calculator.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Simple calculator (Add,Subtract,Multiply,Divide), Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float var_1 , var_2 ;
	char operator ;

	printf("Enter \'+'\ for Add, \'-'\ for Subtract, \'*'\ for Multiply, \'/'\ for Division :  ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&operator);

	printf("Enter the first number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var_1);

	printf("Enter the second number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&var_2);

	switch(operator)
	{
	case '+' :
	{
		printf("%.4f + %.4f = %.4f",var_1,var_2,(var_1 + var_2));
		break ;
	}
	case '-' :
	{
		printf("%.4f - %.4f = %.4f",var_1,var_2,(var_1 - var_2));
		break ;
	}
	case '*' :
	{
		printf("%.4f * %.4f = %.4f",var_1,var_2,(var_1 * var_2));
		break ;
	}
	case '/' :
	{
		printf("%.4f / %.4f = %.4f",var_1,var_2,(var_1 / var_2));
		break ;
	}
	default :
	{
		printf("wrong choice");
		break ;
	}
	}
	return 0;
}
