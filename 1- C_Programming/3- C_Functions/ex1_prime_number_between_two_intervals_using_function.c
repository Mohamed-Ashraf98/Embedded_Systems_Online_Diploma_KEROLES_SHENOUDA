/*
 ============================================================================
 Name        : ex1_prime_number_between_two_intervals_using_function.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : print all prime numbers within the interval entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void prime(int var);

int main()
{
	int i , min , max ;

	printf("Enter the minimum of the interval :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&min);
	printf("Enter the maximum of the interval :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&max);

	printf("prime numbers between %d and %d are :  ",min,max);

	for(i=min;i<=max;i++)
	{
		prime(i);
	}

	return 0;
}

void prime(int var)
{
	int count , check = 0 ;

	if(var>=2)
	{
		for(count=2;count<=var/2;count++)
		{
			if(var%count == 0)
			{
				check = 1 ;
				break;
			}
		}

		if(check == 0)
			printf("%d ",var);
	}
}
