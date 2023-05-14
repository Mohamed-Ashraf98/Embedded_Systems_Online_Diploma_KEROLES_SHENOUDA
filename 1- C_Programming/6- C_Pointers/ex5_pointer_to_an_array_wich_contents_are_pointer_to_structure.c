/*
 ============================================================================
 Name        : ex5_pointer_to_an_array_wich_contents_are_pointer_to_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : show a pointer to an array which contents are pointer to structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define size 3

typedef struct {
	char name[30];
	int ID;
}employee;

int main()
{
	employee emp_1 , emp_2 , emp_3 ;
	employee *arr[size] = { &emp_1 , &emp_2 , &emp_3 };
	employee (*(*ptr)[size]) = &arr;

	int counter = 0;

	for(counter=0; counter<size; counter++)
	{
		printf("Enter the information of employee no.%d\n",counter+1);

		printf("Name of employee no.%d :  ",counter+1);
		fflush(stdout);fflush(stdin);
		gets( (*(*ptr + counter))->name );

		printf("ID of employee no.%d   :  ",counter+1);
		fflush(stdout);fflush(stdin);
		scanf("%d", &((*(*ptr + counter))->ID) );
	}

	printf("\n");

	for(counter=0; counter<size; counter++)
	{
		printf("information of employee no.%d\n",counter+1);

		printf("Name of employee no.%d : %s\n", counter+1, (*(*ptr + counter))->name );

		printf("ID of employee no.%d   : %d\n", counter+1, (*(*ptr + counter))->ID );
	}

	return 0;
}
