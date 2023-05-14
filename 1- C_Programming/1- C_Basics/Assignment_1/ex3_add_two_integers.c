/*
 ============================================================================
 Name        : ex3_add_two_integers.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Program to Add Two Integers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y ;
	printf("Enter the two integers : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&x,&y);

	printf("The sum of two integers you entered :  %d", (x+y) );
	return 0;
}
