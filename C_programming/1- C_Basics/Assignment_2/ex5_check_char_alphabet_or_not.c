/*
 ============================================================================
 Name        : ex5_check_char_alphabet_or_not.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : Enter a character and check if it's alphabet or not, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char var ;

	printf("Enter the character you want to check :  ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&var);

	/*
	range of capital alphabet ( A -> Z) in ASCII table is from  65 to 90
	range of snall alphabet ( a -> z) in ASCII table is from  97 to 122
	*/

	if( ( var >= 65 && var <= 90 ) || ( var >= 97 && var <= 122 ) )
	{
		printf("The character %c is an alphabet.",var);
	}
	else
	{
		printf("The character %c is not an alphabet.",var);
	}
	return 0;
}
