/*
 ============================================================================
 Name        : ex1_check_even_or_odd.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Check if the number is even or odd, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	printf("Enter the number you want to check : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	if(x%2 == 0)
		printf("%d is an even number.",x);
	else
		printf("%d is an odd number.",x);

	return 0;
}
