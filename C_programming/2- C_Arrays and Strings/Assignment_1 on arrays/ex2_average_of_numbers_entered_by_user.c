/*
 ============================================================================
 Name        : ex2_average_of_numbers_entered_by_user.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate the average of numbers entered ny the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int num , count ;
	float sum = 0.0 ;

	printf("Enter the number of values you want to get their average :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	float average[num] ;

	for(count=0;count<num;count++)
	{
		printf("Enter num%d :  ",count+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&average[count]);

		sum += average[count];
	}

	printf("Average =  %.3f", ( sum/num ) );

	return 0;
}
