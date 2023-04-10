/*
 ============================================================================
 Name        : midterm1_Q5_function_to_count_number_of_ones_in_binary_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to count number of ones in binary number, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int binary(int var);

int main()
{
    int num , ones ;

    printf("Enter the number :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    printf("Binary representation of %d is :   ",num);
    ones = binary(num);
    printf("number of ones inside %d are %d",num,ones);

    return 0;
}

int binary(int var)
{
	int i , count = 0 ;

	for(i=0;i<32;i++)
	{
		if(var<<i & 1<<31)
		{
			printf("1");
			count++ ;
		}
		else
			printf("0");
	}
	printf("\n");

	return count ;
}
