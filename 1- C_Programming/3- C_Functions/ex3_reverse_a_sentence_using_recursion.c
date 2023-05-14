/*
 ============================================================================
 Name        : ex3_reverse_a_sentence_using_recursion.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Reverse a sentence entered by the user using Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void reverse(char *track);

int main()
{
	char sentence[100] ;

	printf("Enter the sentence :  ");
	fflush(stdin);fflush(stdout);
	gets(sentence);

	reverse(sentence);

	return 0;
}

void reverse(char *track)
{
	if(*track == '\0')
	{

	}
	else
	{
		track += 1;
		reverse(track);
		track -= 1;
		printf("%c", *(track) );
	}
}
