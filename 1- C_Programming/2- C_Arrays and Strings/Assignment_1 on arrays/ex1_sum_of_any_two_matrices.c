/*
 ============================================================================
 Name        : ex1_sum_of_any_two_matrices.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Sum of any two matrices entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int n_rows , n_columns , i , j ;

	printf("Enter the number of rows :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_rows);
	printf("Enter the number of columns :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_columns);

	float a[n_rows][n_columns] , b[n_rows][n_columns] , resultant[n_rows][n_columns] ;

	printf("Enter the elements of the first matrix :\n");
	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			printf("Enter n%d%d :  ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	printf("Enter the elements of the second matrix :\n");
	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			printf("Enter n%d%d :  ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}

	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			resultant[i][j] = a[i][j] + b[i][j] ;
		}
	}

	printf("The resultant matrix :\n");
	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			printf("%.3f  ",resultant[i][j]);
		}
		printf("\n");
	}
	return 0;
}
