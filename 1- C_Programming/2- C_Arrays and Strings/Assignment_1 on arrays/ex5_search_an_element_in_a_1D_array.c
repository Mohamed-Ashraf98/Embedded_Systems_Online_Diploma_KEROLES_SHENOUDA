/*
 ============================================================================
 Name        : ex5_search_an_element_in_a_1D_array.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Search any elements in a 1D array entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int n_elements , i ;
	float search ;

	printf("Enter the number of elements of the array :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_elements);

	float a[n_elements] ;

	for(i=0;i<n_elements;i++)
	{
		printf("Enter n%d :  ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&a[i]);
	}

	printf("The array you entered :  ");
	for(i=0;i<n_elements;i++)
		printf("%.2f  ",a[i]);
	printf("\n");

	printf("Enter the element you want to search :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&search);

	for(i=0;i<n_elements;i++)
	{
		if(search == a[i])
			break;
	}

	printf("The element is found at location : %d",i+1);

	return 0;
}
