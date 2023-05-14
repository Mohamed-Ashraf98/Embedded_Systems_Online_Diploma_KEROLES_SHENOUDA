/*
 ============================================================================
 Name        : midterm1_Q2_function_to_calculate_square_of_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to take an integer number and calculate it's square root, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

void calc_square(int var);

int main()
{
    int num;

    printf("Enter a +ve integer :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    calc_square(num);

    return 0;
}

void calc_square(int var)
{
	printf("square root of %d is %.3f",var,sqrt(var));
}
