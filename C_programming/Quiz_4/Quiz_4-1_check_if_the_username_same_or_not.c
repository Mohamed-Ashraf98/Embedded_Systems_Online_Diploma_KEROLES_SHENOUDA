/*
 ============================================================================
 Name        : Quiz_4-1_check_if_the_username_same_or_not.c
 Author      : Mohamed Ashraf
 Version     :
 Copyright   : Your copyright notice
 Description : check if the string  entered by the user is same as the user_name or not, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char user_check[20] , user_name[20] ;

	printf("Enter the user check :  ");
	fflush(stdin);fflush(stdout);
	scanf("%s",user_check);

	printf("Enter the user name :  ");
	fflush(stdin);fflush(stdout);
	scanf("%s",user_name);

	/* It doesn't matter if they are different in lower and upper case, still considered identical */
	stricmp(user_check,user_name) ? printf("They are not identical."): printf("They are identical.");

	return 0;
}
