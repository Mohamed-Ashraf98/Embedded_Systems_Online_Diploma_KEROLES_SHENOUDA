/*
 ============================================================================
 Name        : ex4_print_elements_of_an_array_in_reverse_order.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : print elements of an array in reverse order using a pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define size 15

int main()
{
	int counter = 0 , num_of_elements;
	float arr[size];
	float *ptr = arr;     /*   ptr = &arr[0]   */

	printf("Enter the number of elements of the array :  ");
	fflush(stdout);
	scanf("%d",&num_of_elements);

	printf("Enter the elements of the array you want to reverse :\n");
	for(counter=0; counter<num_of_elements; counter++)
	{
		printf("arr[%d] :  ",counter);
		fflush(stdout);
		scanf("%f", (ptr + counter) );
	}

	printf("The array you entered is  ");
	for(counter=0; counter<num_of_elements; counter++)
		printf("%.2f   ", *(ptr + counter) );

	printf("\n");

	printf("The array you entered in reverse order will be  ");
	for(counter = num_of_elements-1; counter>=0; counter--)
		printf("%.2f   ", *(ptr + counter) );

	return 0;
}
