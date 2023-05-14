/*
 ============================================================================
 Name        : ex2_add_two_distances_using_structure.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Add two distances (Inch-Feet system) using structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>

typedef struct{
	int feet;
	float inch;
}distance;

void get_distances(distance *ptr_dis_1,distance *ptr_dis_2);
void add_distances(distance *ptr_dis_1,distance *ptr_dis_2,distance *ptr_sum);

int main()
{
	distance first_dis , second_dis , sum_dis;

	get_distances(&first_dis,&second_dis);
	add_distances(&first_dis,&second_dis,&sum_dis);

	return 0 ;
}

void get_distances(distance *ptr_dis_1,distance *ptr_dis_2)
{
	printf("Enter the information of first distance\n");
	printf("feet :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&ptr_dis_1->feet);
	printf("inch :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_dis_1->inch);

	printf("Enter the information of second distance\n");
	printf("feet :  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&ptr_dis_2->feet);
	printf("inch :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&ptr_dis_2->inch);
}

void add_distances(distance *ptr_dis_1,distance *ptr_dis_2,distance *ptr_sum)
{
	ptr_sum->feet = ptr_dis_1->feet + ptr_dis_2->feet ;
	ptr_sum->inch = ptr_dis_1->inch + ptr_dis_2->inch ;

	if(ptr_sum->inch >= 12.0f)
	{
		ptr_sum->inch -= 12;
		ptr_sum->feet++;
	}

	printf("sum of two distances are  %d feet and %.2f inch",ptr_sum->feet,ptr_sum->inch);
}
