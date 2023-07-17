/*
 =========================================================================================
 Name        : single_linked_list.h
 Author      : Mohamed Ashraf
 Version     : 1.0.0
 Copyright   : Your copyright notice
 date        : Fri, May 19 2023
 time        :
 Description : implementation of the single linked list , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */
//#include "single_linked_list.h"
#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_

/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include "Platforms_Types.h"

/* ----------------------------------------------------------------------------------- */

/* --------------Macro definition section--------------- */
#define D_ENABLE 0              /* for debug purposes */

/* ----------------------------------------------------------------------------------- */

/* -----user_defined data type declaration section------ */
/* create node of the single linked list */
struct node{
    sint32 data;                /* data holds the value of the node */
    struct node *link;          /* link points to the next node */
};


typedef enum {
    list_operation_fail = 0,    /* linked list operation failed */
    list_operation_success,     /* linked list operation performed successfully */
    list_null_pointer           /* NULL pointer passed to the function */
}list_status_t;

/* ----------------------------------------------------------------------------------- */

/* ------------functions declaration section------------ */

/**
  *  @brief   insert node at the beginning of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_node_at_beginning(struct node **ptr_head);


/**
  *  @brief   insert node at the end of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_node_at_end(struct node **ptr_head);


/**
  *  @brief   insert node at any position inside the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t insert_at_position(struct node **ptr_head);


/**
  *  @brief   delete node at the beginnig of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delete_node_at_beginning(struct node **ptr_head);


/**
  *  @brief   delete node at the end of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delete_node_at_end(struct node **ptr_head);


/**
  *  @brief   delete node at any position of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t delet_node_at_position(struct node **ptr_head);


/**
  *  @brief   reverse all nodes of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t reverse_list(struct node **ptr_head);


/**
  *  @brief   delete all nodes of the single linked list
  *  @param   (ptr_head) pointer to the head pointer points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t destroy_list(struct node **ptr_head);


/**
  *  @brief   display all nodes of the single linked list
  *  @param   (head) points to the first node of the list
  *  @retval  (l_status) status of the performed process
  */
list_status_t display_list(struct node *head);


/**
  *  @brief   caculate number of nodes inside the single linked list
  *  @param   (head) points to the first node of the list
  *  @retval  (num_of_nodes) holds the number of nodes inside the list
  */
uint32 list_size(struct node *head);

/* ----------------------------------------------------------------------------------- */

#endif // _SINGLE_LINKED_LIST_H_