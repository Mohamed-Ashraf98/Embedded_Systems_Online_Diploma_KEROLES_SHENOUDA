/*
 =========================================================================================
 Name        : single_linked_list.c
 Author      : Mohamed Ashraf
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Fri, May 19 2023
 time        :
 Description : implementation of the single linked list , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include <stdio.h>
#include <stdlib.h>

#include "single_linked_list.h"

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */

/* ----------------------------------------------------------------------------------- */

/* ------------functions definition section------------- */

/**
  *  @brief   insert node at the beginning of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_node_at_beginning(struct node **ptr_head)
{
    /* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

    /* create a local pointer points to the added node */
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    /* check if the node is allocated in heap or not */
    if(temp == NULL)
    {
        /* node couldn't be allocated in heap */
        l_status = list_operation_fail;       /* linked list operation failed */

        #if D_ENABLE
        printf("node couldnt't be allocated in heap\n");
        #endif

    }

    else
    {
        /* node is allocated in heap successfully */

        /* enter the data and link part of the new node */
        printf("Enter the data of the node you want to insert :  ");
        scanf("%d",&(temp->data) );
        temp->link = NULL;

        /* check if the linked list is empty or not */
        if(*ptr_head == NULL)
        {
            /* linked list is empty */
            /* head pointer points to the newly added node */
            *ptr_head = temp;
        }

        else
        {
            /* linked list isn't empty */

            /* update the link part of the new node */
            temp->link = *ptr_head;
            /* head pointer points to the newly added node */
            *ptr_head = temp;
        }

        /* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("node is allocated and added to the list successfully\n");
        #endif
    }

    return l_status;
}


/**
  *  @brief   insert node at the end of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_node_at_end(struct node **ptr_head)
{
    /* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

    /* create a local pointer points to the first node */
    struct node *l_head = *ptr_head;

    /* create a local pointer points to the added node */
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    /* check if the node is allocated in heap or not */
    if(temp == NULL)
    {
        /* node couldn't be allocated in heap */
        l_status = list_operation_fail;       /* linked list operation failed */

        #if D_ENABLE
        printf("node couldnt't be allocated in heap\n");
        #endif

    }

    else
    {
        /* node is allocated in heap successfully */

        /* enter the data and link part of the new node */
        printf("Enter the data of the node you want to insert :  ");
        scanf("%d",&(temp->data) );
        temp->link = NULL;

        /* check if the linked list is empty or not */
        if(*ptr_head == NULL)
        {
            /* linked list is empty */
            /* head pointer points to the newly added node */
            *ptr_head = temp;
        }

        else
        {
            /* linked list isn't empty */
            while(l_head->link != NULL)
            {
                l_head = l_head->link;        /* next node */
            }
            l_head->link = temp;
        }

        /* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("node is allocated and added to the list successfully\n");
        #endif
    }

    return l_status;
}


/**
  *  @brief   insert node at any position inside the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_at_position(struct node **ptr_head)
{
    /* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

    /* create a local variable to hold the position of the node you want to add */
    uint32 node_position = ZERO_INIT;

    /* create a local variable to hold the number of nodes inside the list */
    uint32 num_of_nodes = list_size(*ptr_head);

    /* create a local variable to traverse the list */
    uint32 counter = 1;

    /* create a local pointer points to the first node */
    struct node *l_head = *ptr_head;

    printf("Enter the position of the node you want to add :  ");
	scanf("%d",&node_position);

    /* check if the node position exceeded the size of list or not */
    if( node_position > num_of_nodes )
	{
        /* node position exceeded the size of the list */
		printf("Error !! you want to add node at position %d but the list only consists of %d nodes\n"
        ,node_position,num_of_nodes);

		l_status = list_operation_fail;       /* linked list operation failed */

        #if D_ENABLE
        printf("Enter a position within the range\n");
        #endif
	}

    else
    {
        /* node position within the range of the size of the list */

        /* create a local pointer points to the added node */
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        /* check if the node is allocated in heap or not */
        if(temp == NULL)
        {
            /* node couldn't be allocated in heap */
            l_status = list_operation_fail;       /* linked list operation failed */

            #if D_ENABLE
            printf("node couldnt't be allocated in heap\n");
            #endif
        }

        else
        {
            /* node is allocated in heap successfully */

            /* enter the data and link part of the new node */
            printf("Enter the data of the node you want to insert :  ");
            scanf("%d",&(temp->data) );
            temp->link = NULL;

            /* check if the position of the node you want to add is at the beginning or not */
            if(node_position == 1)
			{
                /* node is inserted at the beginning of the list */
				temp->link = *ptr_head;
				*ptr_head = temp;            /* head pointer points to the newly added node */
			}

            else
            {
                /* node is inserted at any position except at the beginnig of the list */

                /* traversing the list */
                while(counter < node_position-1)
				{
					l_head = l_head->link;        /* next node */
					counter++;
				}
				
                /* adding the node to the list */
				temp->link = l_head->link;
				l_head->link = temp;
            }
			
			/* linked list operation performed successfully */
			l_status = list_operation_success;

			#if D_ENABLE
			printf("node is allocated and added to the list successfully\n");
			#endif
        }
    }
    
	return l_status;
}


/**
  *  @brief   delete node at the beginnig of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delete_node_at_beginning(struct node **ptr_head)
{
    /* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

    /* create a local pointer points to the first node */
    struct node *temp = *ptr_head;

    /* check if the linked list is empty or not */
    if(*ptr_head == NULL)
    {
        /* linked list is empty */
        l_status = list_operation_fail;       /* linked list operation failed */
        printf("Linked List is empty\n");
    }

    else
    {
        /* linked list isn't empty */
        /* update head pointer to point to the next node */
        *ptr_head = temp->link;
        /* release the node from heap */
        free(temp);

        /* linked list operation performed successfully */
        l_status = list_operation_success;  

        #if D_ENABLE
        printf("node is deleted from the beginnig of the list successfully\n");
        #endif
    }

    return l_status;
}


/**
  *  @brief   delete node at the end of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delete_node_at_end(struct node **ptr_head)
{
	/* create a local variable to return the state of the performed operation */
	list_status_t l_status = ZERO_INIT;
	
	/* create a local pointer points to the first node */
	struct node *temp = *ptr_head;
	
	/* check if the linked list is empty or not */
	if(*ptr_head == NULL)
    {
        /* linked list is empty */
        l_status = list_operation_fail;       /* linked list operation failed */
        printf("Linked List is empty\n");
    }

	else
	{
		/* linked list isn't empty */
		
		/* check the size of the list */
		if( list_size(*ptr_head) == 1 )
		{
			/* list consists of 1 node */
			
			/* update head pointer to NULL */
			*ptr_head = NULL;
			/* release the node from heap */
			free(temp);
		}
		
		else
		{
			/* list has more than 1 node */
			
			/* traverse the list */
			while(temp->link->link != NULL)
			{
				temp = temp->link;            /* next node */
			}

            /* release the last node from heap */
			free(temp->link);

            /* update the new last node */
            temp->link = NULL;
		}
		
		/* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("node is deleted from the end of the list successfully\n");
        #endif
	}

	return l_status;
}


/**
  *  @brief   delete node at any position of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delet_node_at_position(struct node **ptr_head)
{
	/* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

	/* create a local variable to hold the position of the node you want to delete */
    uint32 node_position = ZERO_INIT;

	/* create a local variable to hold the number of nodes inside the list */
    uint32 num_of_nodes = list_size(*ptr_head);

	/* create a local variable to traverse the list */
    uint32 counter = 1;

	/* create a local pointers points to the first node */
    struct node *l_head = *ptr_head;
	struct node *temp = *ptr_head;

    /* check if the linked list is empty or not */
	if(*ptr_head == NULL)
    {
        /* linked list is empty */
        l_status = list_operation_fail;       /* linked list operation failed */
        printf("Linked List is empty\n");
    }

	else
	{
		/* linked list isn't empty */

        printf("Enter the position of the node you want to delete :  ");
	    scanf("%d",&node_position);

	    /* check if the node position exceeded the size of list or not */
        if( node_position > num_of_nodes )
	    {
            /* node position exceeded the size of the list */
            printf("Error !! you want to delete node at position %d but the list only consists of %d nodes\n"
            ,node_position,num_of_nodes);

            l_status = list_operation_fail;       /* linked list operation failed */

            #if D_ENABLE
            printf("Enter a position within the range\n");
            #endif
	    }

        else
        {
            /* node position within the range of the size of the list */

            /* check if the position of the node you want
            to delete is at the beginning or not */
            if(node_position == 1)
            {
                /* node is deleted from the beginning of the list */

                *ptr_head = temp->link;       /* head pointer points to the next node */
                temp->link = NULL;
                free(temp);           		  /* release the node from heap */
            }

            else
            {
                /* node is deleted from any position except at the beginnig of the list */

                /* traversing the list */
                /* l_head reaches the last node before the node you want to delete */
                while(counter < node_position-1)
                {
                    l_head = l_head->link;        /* next node */
                    counter++;
                }

                /* update the temp to point to the node you want to delete */
                temp = l_head->link;

                /* deleting the node from the list */
                l_head->link = temp->link;
                temp->link = NULL;
                free(temp);
            }

            /* linked list operation performed successfully */
            l_status = list_operation_success;

            #if D_ENABLE
            printf("node is deleted from the list successfully\n");
            #endif
        }
    }

	return l_status;
}


/**
  *  @brief   reverse all nodes of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t reverse_list(struct node **ptr_head)
{
	/* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

	/* create a local pointers points to the first node and NULL*/
    struct node *next = *ptr_head;
	struct node *prev = NULL;

	/* check if the linked list is empty or not */
	if(*ptr_head == NULL)
    {
        /* linked list is empty */
        l_status = list_operation_fail;       /* linked list operation failed */
        printf("Linked List is empty\n");
    }

	else
	{
		/* linked list isn't empty */

		/* traversing the list */
		while(*ptr_head != NULL)
		{
			next = (*ptr_head)->link;           /* next node */
			(*ptr_head)->link = prev;         /* reverse the link */
			prev = *ptr_head;                 /* current node */
			*ptr_head = next;                 /* next node */
		}

		/* update the head pointer to point at the first node from the opposite direction */
		*ptr_head = prev;

		/* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("node is deleted from the list successfully\n");
        #endif
	}

	return l_status;
}


/**
  *  @brief   delete all nodes of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t destroy_list(struct node **ptr_head)
{
	/* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

	/* create a local pointer points to the first node */
	struct node *temp = *ptr_head;

	/* check if the linked list is empty or not */
	if(*ptr_head == NULL)
    {
        /* linked list is empty */
        l_status = list_operation_fail;       /* linked list operation failed */
        printf("Linked List is empty\n");
    }

	else
	{
		/* linked list isn't empty */

		/* traversing the list */
		while(*ptr_head != NULL)
		{
			*ptr_head = temp->link;           /* head pointer points to the next node */
			free(temp);                       /* release the node from heap */
			temp = *ptr_head;                 /* temp pointer points to the next node */
		}

		/* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("node is allocated and added to the list successfully\n");
        #endif
	}

	return l_status;
}

/**
  *  @brief   display all nodes of the single linked list
  *  @param   (head) points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t display_list(struct node *head)
{
    /* create a local variable to return the state of the performed operation */
    list_status_t l_status = ZERO_INIT;

    /* check if the linked list is empty or not */
    if(head == NULL)
    {
        /* linked list is empty */
        l_status = list_null_pointer;
        printf("Linked List is empty\n");
    }

    else
    {
        /* linked list isn't empty */
        printf("list :\t");

        while(head != NULL)
        {
            printf("%d\t",head->data);
            head = head->link;            /* next node */
        }
        printf("\n");

        /* linked list operation performed successfully */
        l_status = list_operation_success;

        #if D_ENABLE
        printf("list is displayed successfully\n");
        #endif
    }

    return l_status;
}


/**
  *  @brief   caculate number of nodes inside the single linked list
  *  @param   (head) points to the first node of the list
  *  @retval  (num_of_nodes) holds the number of nodes inside the list
  */
uint32 list_size(struct node *head)
{
    /* create a local variable to hold the number of nodes in the loop */
    uint32 num_of_nodes = ZERO_INIT;

    /* check if the linked list is empty or not */
    if(head == NULL)
    {
        /* linked list is empty */
        num_of_nodes = 0;
    }

    else
    {
        /* linked list isn't empty */
        while(head != NULL)
        {
            num_of_nodes++;
            head = head->link;            /* next node */
        }
    }

    return num_of_nodes;
}