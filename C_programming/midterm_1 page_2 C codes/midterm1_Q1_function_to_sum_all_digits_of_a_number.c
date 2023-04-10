/*
 ============================================================================
 Name        : midterm1_Q1_function_to_sum_all_digits_of_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to take a number and sum all digits, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void sum_digits(int var);

int main()
{
    int num;

    printf("Enter the number :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    sum_digits(num);

    return 0;
}

void sum_digits(int var)
{
	int remainder , sum = 0 ;

	while(var!=0)
	{
		remainder = var%10;
		sum += remainder ;
		var /= 10 ;
	}

	printf("sum = %d",sum);
}
