/*
 ============================================================================
 Name        : midterm1_Q3_print_all_prime_numbers_within_interval.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to print all prime numbers between two numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void print_prime(int var);

int main()
{
    int min , max , i ;

    printf("Enter the minimum of the interval :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&min);
    printf("Enter the maximum of the interval :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&max);

    printf("prime numbers between %d and %d are :  ",min,max);
    for(i=min;i<=max;i++)
    	print_prime(i);

    return 0;
}

void print_prime(int var)
{
	int i , status = 0 ;

	if(var>=2)
	{
		for(i=2;i<=var/2;i++)
		{
			if(var%i == 0)
			{
				status = 1;
				break ;
			}
		}

		if(status == 0)
			printf("%d  ",var);
	}
}
