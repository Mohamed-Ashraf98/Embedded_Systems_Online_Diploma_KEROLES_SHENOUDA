/*
 =========================================================================================
 Name        : static_stack_ds.c
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Wed, Jun 7 2023
 time        :
 Description : Implementation of static stack DS based on array DS , Ansi-style
 =========================================================================================
*/

/* ----------------------------------------------------------------------------------- */

/* ------------------Includes section------------------- */
#include "static_stack_ds.h"

/* ----------------------------------------------------------------------------------- */

/* -----user_defined data type definition section------- */
Sstack_ds_t stack;                     /* holds the values of the created stack */
stack_status_t status = ZERO_INIT;     /* holds the status of the performed operation */

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */
sint32 stack_pop_value = ZERO_INIT;    /* holds the value of the element popped from the stack */
sint32 stack_top_value = ZERO_INIT;    /* holds the value of the top of the stack */
uint32 stack_size_value = ZERO_INIT;   /* holds the number of elements inside the stack */

/* ----------------------------------------------------------------------------------- */

/* ------------functions definition section------------- */

/**
  *  @brief   check if stack is empty or not to avoid stack underflow
  *  @param   my_stack  pointer to the stack that passed by reference
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
  *  @param   my_stack  pointer to the stack that passed by reference
  *  @retval  l_state   holds the status of the stack
  *                     (stack_full)    when the stack is full
  *                     (stack_space)   when the stack is not full
  */
static stack_state_t stack_is_full(Sstack_ds_t *my_stack)
{
    /* create a locatl variable to hold the state of the stack */
    stack_state_t l_state = ZERO_INIT;

    /* check if the stack is full or not */
    if(my_stack->stack_pointer == STACK_MAX_SIZE - 1)
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

        /* initialize the stack pointer with -1 */
        my_stack->stack_pointer = -1;

        /* stack operation performed successfully */
        l_status = stack_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("stack of (%d) elements is created successfully\n",STACK_MAX_SIZE);
        #endif
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_push(Sstack_ds_t *my_stack ,sint32 value)
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

        /* check if the stack is full or not to avoid stack overflow */
        if(stack_is_full(my_stack) == stack_full)
        {
            /* stack is full */

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : stack is full, can't push (%d) to the stack\n",value);
            #endif
        }
        else
        {
            /* stack is not full */

            /* increment the stack pointer to point to the next location */
            (my_stack->stack_pointer)++;
            /* push the element into the stack */
            my_stack->data[my_stack->stack_pointer] = value;

            /* update the value of the top of the stack */
            /* create a local pointer points to the variable stack_top_value */
            /* holds the value of the top of the stack */
            sint32 *ptr_stack_top_value = &stack_top_value;
            /* set the variable to hold the vlaue of the top of the stack */
            *ptr_stack_top_value = my_stack->data[my_stack->stack_pointer];

            /* update the size of stack */
            /* create a local pointer points to the variable stack_size_value */
            /* holds the number of elements inside the stack */
            uint32 *ptr_stack_size_value = &stack_size_value;

            /* set the variable to hold the size of the stack */
            *ptr_stack_size_value = my_stack->stack_pointer + 1;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("value > (%d) is pushed into the stack successfully\n",value);
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

            /* create a local pointer points to the variable stack_pop_value */
            /* holds the value of the element popped from the stack */
            sint32 *ptr_stack_pop_value = &stack_pop_value;

            /* pop the element out of the stack */
            *ptr_stack_pop_value = my_stack->data[my_stack->stack_pointer];
            /* decrement the stack pointer to point to the previous location */
            (my_stack->stack_pointer)--;

            /* update the value of the top of the stack */
            /* create a local pointer points to the variable stack_top_value */
            /* holds the value of the top of the stack */
            sint32 *ptr_stack_top_value = &stack_top_value;
            /* set the variable to hold the vlaue of the top of the stack */
            *ptr_stack_top_value = my_stack->data[my_stack->stack_pointer];

            /* update the size of stack */
            /* create a local pointer points to the variable stack_size_value */
            /* holds the number of elements inside the stack */
            uint32 *ptr_stack_size_value = &stack_size_value;

            /* set the variable to hold the size of the stack */
            *ptr_stack_size_value = my_stack->stack_pointer + 1;

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("value > (%d) is popped out of the stack successfully\n",*ptr_stack_pop_value);
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

            /* create a local pointer points to the variable stack_top_value */
            /* holds the value of the top of the stack */
            sint32 *ptr_stack_top_value = &stack_top_value;

            /* set the variable to hold the vlaue of the top of the stack */
            *ptr_stack_top_value = my_stack->data[my_stack->stack_pointer];

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("value > (%d) is the top of the stack\n",*ptr_stack_top_value);
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

        /* create a local pointer points to the variable stack_size_value */
        /* holds the number of elements inside the stack */
        uint32 *ptr_stack_size_value = &stack_size_value;

        /* set the variable to hold the size of the stack */
        *ptr_stack_size_value = my_stack->stack_pointer + 1;

        /* stack operation performed successfully */
        l_status = stack_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("size of stack is (%d)\n",*ptr_stack_size_value);
        #endif
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if STACK_CONFIG
stack_status_t stack_display(Sstack_ds_t *my_stack)
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

            printf("-------------------------\n");
            printf("ERROR !! : stack is empty\n");
            printf("-------------------------\n");

            /* stack operation failed */
            l_status = stack_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : stack is empty\n");
            #endif
        }
        else
        {
            /* stack is not empty */

            /* create a local variable to traverse the stack and print the elements inside it */
            sint32 l_counter = ZERO_INIT;

            printf("-------------------------\n");
            printf("stack : \n");
            /* traverse the stack */
            for(l_counter = my_stack->stack_pointer; l_counter >= 0; l_counter--)
            {
                /* print each element inside the stack */
                printf("%d\n",my_stack->data[l_counter]);
            }
            printf("-------------------------\n");

            /* stack operation performed successfully */
            l_status = stack_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("stack elements are printed successfully\n");
            #endif
        }
    }

    return l_status;
}
#endif

/* ----------------------------------------------------------------------------------- */