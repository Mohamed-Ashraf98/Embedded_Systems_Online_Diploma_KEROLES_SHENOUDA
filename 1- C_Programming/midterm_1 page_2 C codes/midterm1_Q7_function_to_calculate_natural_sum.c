/*
 ============================================================================
 Name        : midterm1_Q7_function_to_calculate_natural_sum.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate the natural sum of a number entered by the user using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int natural_sum(int var);

int main()
{
    int num , sum = 0 ;

    printf("Enter the number :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    sum = natural_sum(num);

    printf("natural sum of %d is  %d", num, sum);

    return 0;
}

int natural_sum(int var)
{
    if(var==1)
        return 1 ;
    else
        return var+natural_sum(var-1);
}
