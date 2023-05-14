/*
 ============================================================================
 Name        : Quiz_4-3_function_to_reverse_entered_array.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to reverse the elements of input array, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void reverse(float a[],float b[],int size);

int main()
{
	int size , i ;

	printf("Enter the size of the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size);

	float a[size] , b[size] ;

	printf("Enter the elements of the array :\n");
	for(i=0;i<size;i++)
	{
		printf("a[%d] :  ",i);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}

	reverse(a,b,size);

	printf("The array after reversing :  ");
	for(i=0;i<size;i++)
		printf("%.2f  ",b[i]);

	return 0;
}

void reverse(float a[],float b[],int size)
{
	int i , j ;
	for(i = 0 ,j = size-1 ;i<size;i++,j--)
		b[i] = a[j];
}
