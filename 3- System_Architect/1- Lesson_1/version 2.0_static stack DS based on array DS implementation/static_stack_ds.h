/*
 =========================================================================================
 Name        : static_stack_ds.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Wed, Jun 7 2023
 time        :
 Description : Implementation of static stack DS based on array DS , Ansi-style
 =========================================================================================
*/

#ifndef _STATIC_STACK_DS_H_
#define _STATIC_STACK_DS_H_
/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include "Platforms_Types.h"
#include "std_libraries.h"
#include "static_stack_ds_cfg.h"

/* ----------------------------------------------------------------------------------- */

/* -----user_defined data type declaration section------ */

typedef struct{
    sint32 stack_pointer;              /* points to the top of the stack */
    sint32 data[STACK_MAX_SIZE];       /* static stack DS based on array DS */
}Sstack_ds_t;

typedef enum{
    stack_operation_fail = 0,          /* stack operation failed */
    stack_operation_success,           /* stack operation performed successfully */
    stack_null_pointer                 /* NULL pointer passed to the function */
}stack_status_t;

typedef enum{
    stack_empty = 0,                   /* stack is empty */
    stack_full,                        /* stack is full */
    stack_space                        /* stack is neither full nor empty */
}stack_state_t;

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */
extern Sstack_ds_t stack;                     /* holds the values of the created stack */
extern stack_status_t status;                 /* holds the status of the performed operation */
extern sint32 stack_pop_value;                /* holds the value of the element popped from the stack */
extern sint32 stack_top_value;                /* holds the value of the top of the stack */
extern uint32 stack_size_value;               /* holds the number of elements inside the stack */

/* ----------------------------------------------------------------------------------- */

/* ------------functions declaration section------------ */

/**
  *  @brief   initialize/create the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_init(Sstack_ds_t *my_stack);

/* ----------------------------------------------------- */

/**
  *  @brief   push the element into the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @param   value     hold the value of the element you want to push into the stack
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_push(Sstack_ds_t *my_stack ,sint32 value);

/* ----------------------------------------------------- */

/**
  *  @brief   pop the element out of the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_pop(Sstack_ds_t *my_stack);

/* ----------------------------------------------------- */

/**
  *  @brief   show the value of the top of the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_top(Sstack_ds_t *my_stack);

/* ----------------------------------------------------- */

/**
  *  @brief   display the size of the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_size(Sstack_ds_t *my_stack);

/* ----------------------------------------------------- */

/**
  *  @brief   display the elements inside the stack
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (stack_operation_fail)      when the opertion fail
  *                     (stack_operation_success)   when the operation is performed successfully
  *                     (stack_null_pointer)        when NULL pointer is passed to the function
  */
stack_status_t stack_display(Sstack_ds_t *my_stack);

/* ----------------------------------------------------------------------------------- */
#endif //_STATIC_STACK_DS_H_