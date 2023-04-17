/*
 ============================================================================
 Name        : ex3_add_two_complex_numbers_using_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to add two complex numbers entered by the user using structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>

typedef struct{
	float real;
	float imaginary;
}complex;

void get_complex(complex *ptr_num_1,complex *ptr_num_2);
void add_complex(complex *ptr_num_1,complex *ptr_num_2,complex *ptr_sum);

int main()
{
	complex first_num , second_num , sum;

	get_complex(&first_num,&second_num);
	add_complex(&first_num,&second_num,&sum);

	return 0 ;
}

void get_complex(complex *ptr_num_1,complex *ptr_num_2)
{
	printf("Enter the information of first complex number\n");
	printf("real :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_num_1->real);
	printf("imaginary :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_num_1->imaginary);

	printf("Enter the information of second complex number\n");
	printf("real :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_num_2->real);
	printf("imaginary :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_num_2->imaginary);
}

void add_complex(complex *ptr_num_1,complex *ptr_num_2,complex *ptr_sum)
{
	ptr_sum->real = ptr_num_1->real + ptr_num_2->real ;
	ptr_sum->imaginary = ptr_num_1->imaginary + ptr_num_2->imaginary ;

	printf("sum of two complex numbers :  %.2f  +  %.2fi",ptr_sum->real,ptr_sum->imaginary);
}
