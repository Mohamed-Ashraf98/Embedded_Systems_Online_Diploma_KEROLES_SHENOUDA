/*
 ============================================================================
 Name        : ex2_find_length_of_string_without_using_strlen_function.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Find the lentgh of a string entered by the user without strlen() function, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	char sentence[100] ;
	int i = 0 ;

	printf("Enter the string :  ");
	fflush(stdin);fflush(stdout);
	gets(sentence);
	printf("The string you entered is :  %s\n",sentence);

	while(sentence[i] != '\0')
		i++ ;

	printf("The length of the string is :  %d",i);

	return 0;
}
