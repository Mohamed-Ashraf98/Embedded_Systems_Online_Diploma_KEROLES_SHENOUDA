/*
 ============================================================================
 Name        : ex3_transpose_of_any_matrix.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Transpose of any matrix entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int n_rows , n_columns , i , j ;

	printf("Enter the number of rows of the matrix :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_rows);
	printf("Enter the number of columns of the matrix :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n_columns);

	float matrix[n_rows][n_columns] , transpose[n_columns][n_rows] ;

	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			printf("Enter a%d%d :  ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix[i][j]);
		}
	}

	printf("The matrix you entered :\n");
	for(i=0;i<n_rows;i++)
	{
		for(j=0;j<n_columns;j++)
		{
			printf("%.2f  ",matrix[i][j]);
		}
		printf("\n");
	}

	/* Calculating the transpose of the matrix*/
	for(i=0;i<n_columns;i++)
	{
		for(j=0;j<n_rows;j++)
		{
			transpose[i][j] = matrix[j][i] ;
		}
	}

	printf("The transpose of the matrix is :\n");
	for(i=0;i<n_columns;i++)
	{
		for(j=0;j<n_rows;j++)
		{
			printf("%.2f  ",transpose[i][j]);
		}
		printf("\n");
	}

	return 0;
}
