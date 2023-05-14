/*
 ============================================================================
 Name        : ex_break_statement.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Find average of n non-negative numbers entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	float N , sum = 0 , average ;
	int count = 0 ;

	printf("Enter any non negative number : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&N);

	while (N >= 0.0)
	{
		if(N <0)
			break ;

		count++ ;
		sum += N ;

		printf("Enter any non negative number : ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&N);

	}

	average = sum/count ;
	printf("Average = %.3f",average);

	return 0;
}
