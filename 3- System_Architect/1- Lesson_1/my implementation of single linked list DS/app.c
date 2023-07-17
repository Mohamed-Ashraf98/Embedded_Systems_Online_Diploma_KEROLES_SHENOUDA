/*
 =========================================================================================
 Name        : app.c
 Author      : Mohamed Ashraf
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Fri, May 19 2023
 time        :
 Description : main function for implementing the single linked list , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */
struct node *head = NULL;       /* head pointer points to the first node of the list */

/* ----------------------------------------------------------------------------------- */

int main()
{
    uint8 choice = ZERO_INIT;

    while(1)
    {
        printf("-------------------------------------\n");
        printf("1  >> Insert node at the beginning\n");
        printf("2  >> Insert node at the end\n");
        printf("3  >> Insert node at certain position\n");
        printf("4  >> Delete node at the beginning\n");
        printf("5  >> Delete node at the end\n");
        printf("6  >> Delete node at certain position\n");
        printf("7  >> reverse the list\n");
        printf("8  >> Delete the list\n");
        printf("9  >> Display the list\n");
        printf("10 >> Length of the list\n");
        printf("11 >> Exit\n");
        printf("-------------------------------------\n");

        printf("Enter your choice :  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case  1  :  insert_node_at_beginning(&head);
                break;
        
            case  2  :  insert_node_at_end(&head);
                break;
        
            case  3  :  insert_at_position(&head);
                break;
        
            case  4  :  delete_node_at_beginning(&head);
                break;
        
            case  5  :  delete_node_at_end(&head);
                break;
        
            case  6  :  delet_node_at_position(&head);
                break;
            
            case  7  :  reverse_list(&head);
                break;

            case  8  :  destroy_list(&head);
                break;
        
            case  9  :  display_list(head);
                break;
        
            case  10 :  printf("list consists of %d nodes\n", list_size(head) );
                break;
        
            case  11 :  exit(0);
                break;
        
            default  :  printf("please choose one of the above choices\n");
                break;
        }
    }
    
    return 0;
}