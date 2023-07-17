/*
 =========================================================================================
 Name        : app.c
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
#include "app.h"

/* ----------------------------------------------------------------------------------- */

/* -------------------Global section-------------------- */
sint32 var_1 = -13;
float32 var_2 = 73.15;
uint8 var_3 = 'M';

/* ----------------------------------------------------------------------------------- */

int main()
{
    /* initialize the stack */
    status = stack_init(stack);

    /* push var_1 into the stack */
    status = stack_push(stack,&var_1);

    /* var_1 is the top of the stack */
    printf("the top of the stack is (%d)\n",*(sint32 *)stack_top_value);

    /* push var_2 into the stack */
    status = stack_push(stack,&var_2);

    /* var_2 is the top of the stack */
    printf("the top of the stack is (%.3f)\n",*(float32 *)stack_top_value);

    /* push var_3 into the stack */
    status = stack_push(stack,&var_3);

    /* var_3 is the top of the stack */
    printf("the top of the stack is (%c)\n",*(uint8 *)stack_top_value);

    /* display the size of the stack */
    status = stack_size(stack);
    printf("size of stack is (%d)\n",stack_size_value);

    /* pop var_3 out of the stack */
    status = stack_pop(stack);
    printf("element popped from stack is (%c)\n",*(uint8 *)stack_pop_value);

    /* var_2 is the top of the stack */
    printf("the top of the stack is (%.3f)\n",*(float32 *)stack_top_value);

    /* pop var_2 out of the stack */
    status = stack_pop(stack);
    printf("element popped from stack is (%.3f)\n",*(float32 *)stack_pop_value);

    /* var_1 is the top of the stack */
    printf("the top of the stack is (%d)\n",*(sint32 *)stack_top_value);

    /* pop var_1 out of the stack */
    status = stack_pop(stack);
    printf("element popped from stack is (%d)\n",*(sint32 *)stack_pop_value);

    /* display the size of the stack */
    status = stack_size(stack);
    printf("size of stack is (%d)\n",stack_size_value);

    /* try to pop from empty stack */
    status = stack_pop(stack);

    /* try to call the stack_top from empty stack */
    status = stack_top(stack);

    /* destory the stack */
    status = stack_destroy(stack);

    return 0;
}