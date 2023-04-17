/*
 ============================================================================
 Name        : ex5_calculate_area_of_circle_by_passing_arguments_to_macros.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate the area of a circle by passing arguments to macros, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define pi 3.141592654
#define area(r) pi*r*r

int main()
{
	float radius;

	printf("Enter the radius of the circle :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&radius);

	printf("The area of the circle is   %.3f", area(radius) );

	return 0 ;
}
