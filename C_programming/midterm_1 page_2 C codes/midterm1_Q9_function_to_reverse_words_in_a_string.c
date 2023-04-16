/*
 ============================================================================
 Name        : midterm1_Q9_function_to_reverse_words_in_a_string.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Function to reverse words in a string, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void reverse(char *str_rev,int size);

int main()
{
	char sentence[100];

	printf("Enter string :  ");
	fflush(stdin);fflush(stdout);
	gets(sentence);

	reverse(sentence,strlen(sentence));

	return 0 ;
}

void reverse(char *str,int size)
{
	int i , j , k=0 ;
	char word[50];

	for(i=size-1;i>=0;i--)
	{
		if( *(str + i) != ' ' )
		{
			word[k] = *(str + i);
			k++;
		}

		else
		{
			for(j=k-1;j>=0;j--)
				printf("%c",word[j]);

			printf(" ");
			k = 0;
		}
	}

	if(k != 0)
	{
		for(j=k-1;j>=0;j--)
			printf("%c",word[j]);
	}

}
