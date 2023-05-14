/*
 ============================================================================
 Name        : Quiz_4-5_function_clears_specific_bit_in_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function that clears a specific bit in a number entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int clear_bit(int var,int bit);
void binary(int var);

int main()
{
	int num , bit ;

	printf("Enter the number :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);

	/* bit position from 0 --> 31 as size of integer is 4 bytes (32 bits) */
	printf("Enter the bit position (0-->31) that you will clear :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&bit);

	binary(num);

	num = clear_bit(num,bit);
	printf("The number will be %d after clearing bit %d\n",num,bit);
	binary(num);

	return 0;
}

/* clearing a specific bit of any number */
int clear_bit(int var,int bit)
{
	return var & ~(1<<bit) ;
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
