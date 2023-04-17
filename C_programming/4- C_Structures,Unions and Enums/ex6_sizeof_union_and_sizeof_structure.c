/*
 ============================================================================
 Name        : ex6_sizeof_union_and_sizeof_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : size of union and size of structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>

typedef union{
	char name[32];
	float salary;
	int worker_number;
}u_job;

typedef struct{
	char name[32];
	float salary;
	int worker_number;
}s_job;

int main()
{
	printf("size of union     =  %d bytes\n",sizeof(u_job));
	printf("size of structure =  %d bytes\n",sizeof(s_job));

	return 0 ;
}
