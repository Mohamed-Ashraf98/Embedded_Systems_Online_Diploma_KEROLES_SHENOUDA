/*
 ============================================================================
 Name        : Quiz_4-8_function_to_print_last_occurance_of_a_number.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : print the last occurance of a number in an array entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void last_occurance(float *ptr,float check,int size);

int main()
{
	int size , i ;
	float check ;

	printf("Enter the size of the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);

	float a[size] ;

	for(i=0;i<size;i++)
	{
		printf("enter a[%d] :  ",i);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}

	printf("The array you entered :  ");
	for(i=0;i<size;i++)
		printf("%.2f  ",a[i]);
	printf("\n");

	printf("Enter the number you want to check :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&check);

	last_occurance(a,check,size);

	return 0;
}

void last_occurance(float *ptr,float check,int size)
{
	int i , state = 0 ;

	for(i=size-1;i>=0;i--)
	{
		if(check == ptr[i])
		{
			state = 1;
			break ;
		}
	}

	if(state == 1)
		printf("last occurance of %.2f exist at position %d",check,i+1);
	else
		printf("%.2f does not exist in the array",ptr[i]);
}
