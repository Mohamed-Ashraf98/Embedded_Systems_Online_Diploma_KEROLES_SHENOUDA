/*
 =========================================================================================
 Name        : dynamic_stack_ds.c
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Fri, Jun 9 2023
 time        :
 Description : Implementation of dynamic stack DS based on array DS , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include "dynamic_stack_ds.h"

/* ----------------------------------------------------------------------------------- */

/* -----user_defined data type definition section------- */
Sstack_ds_t *stack = NULL;                  /* pointer points to the stack created in heap */
stack_status_t status = ZERO_INIT;          /* holds the status of the performed operation */

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */
void *stack_pop_value = NULL;               /* pointer points to the element popped from the stack */
void *stack_top_value = NULL;               /* pointer points to the top of the stack */
uint32 stack_max_size_value = ZERO_INIT;    /* holds the maximum number of elements inside the stack */
uint32 stack_size_value = ZERO_INIT;        /* holds the number of elements inside the stack */

/* ----------------------------------------------------------------------------------- */

/* ------------functions definition section------------- */

/**
  *  @brief   check if stack is empty or not to avoid stack underflow
  *  @param   my_stack  pointer to the allocated stack passed by reference
  *  @retval  l_state   holds the status of the stack
  *                     (stack_empty)   when the stack is empty
  *                     (stack_space)   when the stack is not empty
  */
static stack_state_t stack_is_empty(Sstack_ds_t *my_stack)
{
    /* create a locatl variable to hold the state of the stack */
    stack_state_t l_state = ZERO_INIT;

    /* check if the stack is empty or not */
    if(my_stack->stack_pointer == -1)
    {
        /* stack is empty */
        l_state = stack_empty;
    }
    else
    {
        /* stack is not empty */
        l_state = stack_space;
    }

    return l_state;
}

/* ----------------------------------------------------- */

/**
  *  @brief   check if stack is full or not to avoid stack overflow
  *  @param   my_stack  pointer to the allocated stack passed by reference
  *  @retval  l_state   holds the status of the stack
  *                     (stack_full)    when the stack is full
  *                     (stack_space)   when the stack is not full
  */
static stack_state_t stack_is_full(Sstack_ds_t *my_stack)
{
    /* create a locatl variable to hold the state of the stack */
    stack_state_t l_state = ZERO_INIT;

    /* check if the stack is full or not */
    if(my_stack->stack_pointer == stack_max_size_value - 1)
    {
        /* stack is full */
        l_state = stack_full;
    }
    else
    {
        /* stack is not full */
        l_state = stack_space;
    }

    return l_state;
}

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_init(Sstack_ds_t *my_stack)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* allocate the stack in the heap */
    my_stack = (Sstack_ds_t *)malloc( sizeof(Sstack_ds_t) );

    /* check if the stack is allocated in heap or not */
    if(my_stack == NULL)
    {
        /* stack couldnt't be allocated in heap */

        /* stack operation failed */
        l_status = stack_operation_fail;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : stack couldn't be allocated in the heap\n");
        #endif
    }
    else
    {
        /* stack is allocated in heap successfully */

        /* stack operation performed successfully */
        l_status = stack_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("stack is allocated in heap successfully\n");
        #endif

        /* enter the max size of stack */
        printf("Enter the max size of stack :  ");
        scanf("%d",&stack_max_size_value);

        /* allocate the array of pointers according to the size entered */
        my_stack->data = (void **)malloc(stack_max_size_value * sizeof(void *));

        /* check if the array is allocated in heap or not */
        if(my_stack->data == NULL)
        {
            /* the array couldn't be allocated in heap */

            /* free the allocated memory pointed by my_stack in heap */
            free(my_stack);

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : the array of pointers couldn't be allocated in the heap\n");
            #endif
        }
        else
        {
            /* the array of pointers is allocated in heap successfully */

            /* initialize the stack */

            /* initialize the stack pointer with -1 */
            my_stack->stack_pointer = -1;
            /* number of elements inside the stack is zero */
            stack_size_value = ZERO_INIT;

            /* update the stack to point to the allocated memory in heap */
            stack = my_stack;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("stack of (%d) elements is allocated in the heap successfully\n",stack_max_size_value);
            #endif
        }
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_push(Sstack_ds_t *my_stack ,void *ptr_value)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if( (my_stack == NULL) || (ptr_value == NULL) )
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = stack_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the stack is full or not to avoid stack overflow */
        if(stack_is_full(my_stack) == stack_full)
        {
            /* stack is full */

            /* pointer points to the element popped from the stack */
            stack_pop_value = NULL;

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : stack is full, can't push to the stack\n");
            #endif
        }
        else
        {
            /* stack is not full */

            /* increment the stack pointer to point to the next location */
            (my_stack->stack_pointer)++;
            /* push the element into the stack */
            my_stack->data[my_stack->stack_pointer] = ptr_value;

            /* update the pointer that points to the top of the stack */
            /* pointer points to the top of the stack */
            stack_top_value = ptr_value;

            /* update the size of stack */
            /* holds the number of elements inside the stack */
            stack_size_value = my_stack->stack_pointer + 1;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is pushed into the stack successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_pop(Sstack_ds_t *my_stack)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_stack == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = stack_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the stack is empty or not to avoid stack underflow */
        if(stack_is_empty(my_stack) == stack_empty)
        {
            /* stack is empty */

            /* pointer points to the element popped from the stack */
            stack_pop_value = NULL;
            /* pointer points to the top of the stack */
            stack_top_value = NULL;

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : stack is empty, can't pop from empty stack\n");
            #endif
        }
        else
        {
            /* stack is not empty */

            /* pop the element out of the stack */
            /* pointer points to the element popped from the stack */
            stack_pop_value = my_stack->data[my_stack->stack_pointer];
            /* decrement the stack pointer to point to the previous location */
            (my_stack->stack_pointer)--;

            /* update the pointer that points to the top of the stack */
            /* pointer points to the top of the stack */
            stack_top_value = my_stack->data[my_stack->stack_pointer];

            /* update the size of stack */
            /* holds the number of elements inside the stack */
            stack_size_value = my_stack->stack_pointer + 1;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is popped out of the stack successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_top(Sstack_ds_t *my_stack)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_stack == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = stack_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the stack is empty or not to avoid stack underflow */
        if(stack_is_empty(my_stack) == stack_empty)
        {
            /* stack is empty */

            /* pointer points to the element popped from the stack */
            stack_pop_value = NULL;
            /* pointer points to the top of the stack */
            stack_top_value = NULL;

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : stack is empty, can't display the top of stack from empty stack\n");
            #endif
        }
        else
        {
            /* stack is not empty */
            
            /* update the pointer that points to the top of the stack */
            /* pointer points to the top of the stack */
            stack_top_value = my_stack->data[my_stack->stack_pointer];

            /* update the size of stack */
            /* holds the number of elements inside the stack */
            stack_size_value = my_stack->stack_pointer + 1;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("the top of the stack is displayed successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_size(Sstack_ds_t *my_stack)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_stack == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = stack_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* update the size of stack */
        /* holds the number of elements inside the stack */
        stack_size_value = my_stack->stack_pointer + 1;

        /* stack operation performed successfully */
        l_status = stack_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("size of stack is (%d)\n",stack_size_value);
        #endif
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_destroy(Sstack_ds_t *my_stack)
{
    /* create a local variable to hold the status of the performed operation */
    stack_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_stack == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = stack_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* free the allocated memories from heap */
        free(my_stack->data);
        free(my_stack);

        /* initialize the pointer with NULL  to avoid dangling pointer */
        my_stack = NULL;

        /* stack operation performed successfully */
        l_status = stack_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("stack is deallocated from the heap successfully\n");
        #endif
    }

    return l_status;
}
#endif

/* ----------------------------------------------------------------------------------- */