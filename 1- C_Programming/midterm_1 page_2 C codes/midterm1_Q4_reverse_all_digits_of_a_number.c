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

int reverse_digits(int var);

int main()
{
    int num , num_rev ;

    printf("Enter +ve integer :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&num);

    num_rev = reverse_digits(num);
    printf("%d after reversing its digits will be :  %d", num, num_rev);

    return 0;
}

int reverse_digits(int var)
{
	int remainder = 0 , result = 0 ;

	while(var!=0)
	{
		remainder = var%10 ;
		result = result*10 + remainder ;
		var /= 10;
	}

	return result ;
}
