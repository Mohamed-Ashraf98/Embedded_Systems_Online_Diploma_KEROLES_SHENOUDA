/*
 ============================================================================
 Name        : midterm1_Q10_function_to_count_max_number_of_ones_in_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to count the maximum number of ones between two zeros in a number entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int max_ones(int var);

int main()
{
	int num , ones ;

	printf("Enter the number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	ones = max_ones(num);
	printf("maximum number of ones between to zeros are %d",ones);

	return 0 ;
}

int max_ones(int var)
{
	int i , count = 0 ;

	printf("Binary representation of %d is  ",var);
	for(i=31;i>=0;i--)
		printf("%d", ( var>>i & 1 ? 1 : 0 ) );
	printf("\n");

	while(var!=0)
	{
		var &= (var<<1);
		count++;
	}

	return count ;
}
