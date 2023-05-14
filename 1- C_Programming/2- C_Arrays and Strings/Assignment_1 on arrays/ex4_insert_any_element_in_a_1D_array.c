/*
 ============================================================================
 Name        : ex4_insert_any_element_in_a_1D_array.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Insert any element at any position in a 1D array entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int n_elements , i , pos ;
	float data ;

	printf("Enter the number of elements of the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_elements);

	float a[n_elements] , b[n_elements + 1];

	for(i=0;i<n_elements;i++)
	{
		printf("Enter n%d :  ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}

	printf("The array you entered :  ");
	for(i=0;i < n_elements;i++)
		printf("%.2f ",a[i]);
	printf("\n");

	printf("Enter the value of the element you want to insert in the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&data);
	printf("Enter the position of the element you want to insert in the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&pos);

	for(i=0;i < pos-1;i++)
		b[i] = a[i] ;

	b[pos-1] = data ;

	for(i=pos;i < n_elements+1;i++)
		b[i] = a[i-1] ;

	printf("The new array after insertion :  ");
	for(i=0;i < n_elements+1;i++)
		printf("%.2f ",b[i]);

	return 0;
}
