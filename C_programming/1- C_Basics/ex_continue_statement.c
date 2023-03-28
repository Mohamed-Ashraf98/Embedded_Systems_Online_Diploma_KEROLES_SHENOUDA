/*
 ============================================================================
 Name        : ex_continue_statement.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : finding the product of n integers entered by the user(skip if user entered zero), Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int N , i , var , mul = 1 ;

	printf("Enter the number of non-zero integers you want to multiply :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		printf("Enter n%d :  ",i);
		fflush(stdin);fflush(stdout);
		scanf("%d",&var);

		if(var == 0)
			continue ;

		mul *= var ;

	}
	printf("Product = %d",mul);

	return 0;
}
