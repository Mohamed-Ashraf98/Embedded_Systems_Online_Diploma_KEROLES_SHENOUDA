/*
 ============================================================================
 Name        : ex1_find_frequency_of_char_in_a_string.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Find the frequency of a certain char in a string entered by the user, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] ;
	char frequency ;
	int i , count = 0 ;

	printf("Enter the sentence :  ");
	fflush(stdin);fflush(stdout);
	gets(sentence);
	printf("The sentence you entered is :  %s\n",sentence);

	printf("Enter the character you want to know how many it's repeated :  ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&frequency);

	for(i=0;i<strlen(sentence);i++)
	{
		if(sentence[i] == frequency)
			count++ ;
	}

	printf("The character %c is repeated %d times.",frequency,count);

	return 0;
}
