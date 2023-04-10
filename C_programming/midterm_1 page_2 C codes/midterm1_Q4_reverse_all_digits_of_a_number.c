/*
 ============================================================================
 Name        : midterm1_Q4_reverse_all_digits_of_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to reverse digits of a number, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void reverse_digits(int var);

int main()
{
    int num ;

    printf("Enter +ve integer :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    printf("%d after reversing its digits will be :  ",num);

    reverse_digits(num);

    return 0;
}

void reverse_digits(int var)
{
	int remainder = 0 ;

	while(var!=0)
	{
		remainder = var%10 ;
		var /= 10;
		printf("%d",remainder);
	}
}
