/*
 ============================================================================
 Name        : ex2_check_the.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : check if the alphabet is vowel or not, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x;
	printf("Enter the alphabet you want to check : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&x);

	switch(x)
	{
	case 'A':
	case 'a':
	case 'I':
	case 'i':
	case 'E':
	case 'e':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
	{
		printf("%c is a vowel.",x);
		break ;
	}
	default :
	{
		printf("%c is a consonant.",x);
		break ;
	}
	}
	return 0;
}
