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

void reverse(float *ptr_a,int size);

int main()
{
    int size , i = 0 ;

    printf("Enter the size of the array :  ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&size);

    float a[size] ;

    printf("Enter the elements if the array :\n");
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

    reverse(a,size);

    return 0;
}

void reverse(float *ptr_a,int size)
{
    int i = 0 ;

    printf("The array after reverse will be :  ");
    for(i=size-1;i>=0;i--)
        printf("%.2f  ",ptr_a[i]);
}
