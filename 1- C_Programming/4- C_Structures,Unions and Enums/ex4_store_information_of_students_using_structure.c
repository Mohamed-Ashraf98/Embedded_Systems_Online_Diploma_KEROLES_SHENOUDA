/*
 ============================================================================
 Name        : ex4_store_information_of_students_using_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : store information of 10 students entered by the user and display it, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define size 10

typedef struct student{
	char name[30];
	int roll;
	float marks;
}std_info;

void get_students_info(std_info *ptr_students);
void display_students_info(std_info *ptr_students);

int main()
{
	std_info students[size];

	get_students_info(students);
	display_students_info(students);

	return 0 ;
}

void get_students_info(std_info *ptr_students)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("Enter the student_%d roll number  :   ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&(ptr_students[i].roll) );

		printf("Enter the student_%d name         :   ",i+1);
		fflush(stdin);fflush(stdout);
		fgets(ptr_students[i].name,30,stdin);

		printf("Enter the student_%d marks        :   ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&(ptr_students[i].marks) );
	}
}

void display_students_info(std_info *ptr_students)
{
	int i;

	for(i=0;i<size;i++)
	{
		printf("student_%d roll number :  %d\n",i+1,ptr_students[i].roll);
		printf("student_%d name        :  %s",i+1,ptr_students[i].name);
		printf("student_%d marks       :  %.2f\n",i+1,ptr_students[i].marks);
	}
}
