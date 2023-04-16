/*
 ============================================================================
 Name        : midterm1_Q8_function_to_reverse_elements_of_array.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to reverse the elements of the array, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void reverse(float *ptr_a,float *ptr_rev,int size);

int main()
{
    int size , i = 0;

    printf("Enter the size of the array :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&size);

    float a[size] , a_rev[size];

    printf("Enter the elements if the array\n");
    for(i=0;i<size;i++)
    {
        printf("a[%d] :  ",i);
        fflush(stdin);fflush(stdout);
        scanf("%f",&a[i]);
    }

    printf("The array you entered :  ");
    for(i=0;i<size;i++)
        printf("%.2f  ",a[i]);
    printf("\n");

    reverse(a,a_rev,size);

    printf("The reverse of the array you entered :  ");
    for(i=0;i<size;i++)
    	printf("%.2f  ",a_rev[i]);

    return 0;
}

void reverse(float *ptr_a,float *ptr_rev,int size)
{
    int i , j;

    for(i=0,j=size-1;i<size;i++,j--)
        *(ptr_rev + i) = *(ptr_a + j);
}
