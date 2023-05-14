/*
 ============================================================================
 Name        : Quiz_4-7_check_number_power_of_3_or_not.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : check number entered by the user whether it is a power of 3 or not, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

void check(int var);

int main()
{
	int num ;

	printf("Enter the number you want to check :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	check(num);

	return 0;
}

void check(int var)
{
	double power ;

	if(var <= 0)
		printf("Enter a positive number\n");
	else
	{
		power = log(var) / log(3) ;

		if(power == trunc(power))
			printf("%d is a power of 3 as 3 ^ %d = %d\n",var,(int)power,var);
		else
			printf("%d is not a power of 3",var);
	}
}
