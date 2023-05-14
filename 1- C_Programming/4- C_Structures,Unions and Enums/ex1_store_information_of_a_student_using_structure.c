/*
 ============================================================================
 Name        : ex1_store_information_of_a_student_using_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : store information of a student entered by the user and display it, Ansi-style
 ============================================================================
 */

#include <stdio.h>

typedef struct student{
	char name[30];
	int roll;
	float marks;
}std_info;

void get_student_info(std_info *ptr_std_1);
void display_student_info(std_info *ptr_std_1);

int main()
{
	std_info student_1;

	get_student_info(&student_1);
	display_student_info(&student_1);

	return 0 ;
}

void get_student_info(std_info *ptr_std_1)
{
	printf("Enter the student name         :   ");
	fflush(stdin);fflush(stdout);
	fgets(ptr_std_1->name,30,stdin);

	printf("Enter the student roll number  :   ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&ptr_std_1->roll);

	printf("Enter the student marks        :   ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_std_1->marks);
}

void display_student_info(std_info *ptr_std_1)
{
	printf("student name        :  %s",ptr_std_1->name);
	printf("student roll number :  %d\n",ptr_std_1->roll);
	printf("student marks       :  %.2f",ptr_std_1->marks);
}
