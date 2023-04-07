/*
 ============================================================================
 Name        : Quiz_4-2_swapping_2_arrays_of_different_lengths.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : swapping elements of 2 arrays of different lengths, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int size_1 , size_2 , check_size , i ;
	float temp ;

	printf("Enter the size of the first array  :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size_1);

	printf("Enter the size of the second array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&size_2);

	/* check_size will hold the bigger size */
	check_size = size_1 >= size_2 ? size_1 : size_2 ;
	float a[check_size] , b[check_size] ;

	printf("Enter the elements of the first array :\n");
	for(i=0;i<size_1;i++)
	{
		printf("Enter a%d :  ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}

	printf("Enter the elements of the second array :\n");
	for(i=0;i<size_2;i++)
	{
		printf("Enter b%d :  ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&b[i]);
	}

	/* swapping elements of array a with array b */
	for(i=0;i<check_size;i++)
	{
		temp = a[i] ;
		a[i] = b[i] ;
		b[i] = temp ;
	}

	/* printing the two arrays after swap */
	printf("first array :  ");
	for(i=0;i<size_2;i++)
		printf("%.2f  ",a[i]);

	printf("\n");

	printf("second array :  ");
	for(i=0;i<size_1;i++)
		printf("%.2f  ",b[i]);

	return 0;
}
