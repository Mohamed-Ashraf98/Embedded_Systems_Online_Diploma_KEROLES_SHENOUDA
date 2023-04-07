/*
 ============================================================================
 Name        : Quiz_4-6_check_specific_bit_of_a_number_is_1_or_0.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : check a specific bit of a number entered by the user is 1 or 0, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void check_bit(int var,int bit);
void binary(int var);

int main()
{
	int num , bit ;

	printf("Enter the number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	/* bit position from 0 --> 31 as size of integer is 4 bytes (32 bits) */
	printf("Enter the bit position (0-->31) that you want to check :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&bit);

	binary(num);
	check_bit(num,bit);

	return 0;
}

/* checking a specific bit of any number is 1 or 0 */
void check_bit(int var,int bit)
{
	if(var>>bit & 1)
		printf("The bit number %d of %d is : 1",bit,var);
	else
		printf("The bit number %d of %d is : 0",bit,var);
}

/* binary representation of any number */
void binary(int var)
{
	int i ;
	printf("The binary representation of %d is  ",var);
	for(i=0;i<32;i++)
		printf("%d", (var<<i & 1<<31) ? 1 : 0 );
	printf("\n");
}
