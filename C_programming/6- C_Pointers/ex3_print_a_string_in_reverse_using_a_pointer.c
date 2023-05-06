/*
 ============================================================================
 Name        : ex3_print_a_string_in_reverse_using_a_pointer.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : print a string in reverse using a pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int counter = 0 , rev_counter = 0;
	char sentence[50] , reverse[50] = {0} ;
	char *ptr = sentence;        /* ptr = &sentence[0] */
	char *rev_ptr = reverse;     /* rev_ptr = &reverse[0] */

	printf("Enter the sentence you want to reverse :  ");
	fflush(stdout);
	gets(sentence);

	while( *(ptr + counter) != '\0' )
		counter++;

	for(counter = counter-1; counter>=0; counter--, rev_counter++)
		*(rev_ptr + rev_counter) = *(ptr + counter);

	printf("The sentence you entered in reverse will be :  %s\n",rev_ptr);

	return 0;
}
