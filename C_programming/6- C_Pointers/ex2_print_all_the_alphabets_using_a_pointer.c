/*
 ============================================================================
 Name        : ex2_print_all_the_alphabets_using_a_pointer.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : print all the alphabets using a pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int counter=0;
	char alphabets[27];
	char *ptr = alphabets;    /* ptr = &alphabets[0] */

	for(counter=0; counter<26; counter++)
		*(ptr + counter) = 'A' + counter ;

	/*     *(ptr + counter) is equivalent to alphabets[counter]     */

	printf("Alphabets are :  ");
	for(counter=0; counter<27; counter++)
		printf("%c  ", alphabets[counter] );

	return 0;
}
