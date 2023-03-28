/*
 ============================================================================
 Name        : ex3_reverse_string_without_using_library_function.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Reverse the string entered by the user without using library function(only strlen is allowed), Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] ;
	int i , j ;

	printf("Enter the sentence you want to reverse :  ");
	fflush(stdin);fflush(stdout);
	gets(sentence);
	printf("The sentence you entered is :  %s\n",sentence);

	/* add one more space for the NULL character as strlen() doesn't count the null character */
	char reverse[strlen(sentence) + 1] ;

	for(i=0,j=strlen(sentence)-1 ; i < strlen(sentence) ; i++,j--)
	{
		reverse[i] = sentence[j] ;
	}
	reverse[strlen(sentence)] = '\0' ; /* NULL char is added manually at the end of the reversed string */

	printf("The string reversed :  %s",reverse);

	return 0;
}
