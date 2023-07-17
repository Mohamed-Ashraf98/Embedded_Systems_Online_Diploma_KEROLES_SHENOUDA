/*
 =========================================================================================
 Name        : app.c
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
#include "app.h"

/* ----------------------------------------------------------------------------------- */

int main()
{
    /* initialize the stack */
    status = stack_init(&stack);

    /* push elements into the stack */
    status = stack_push(&stack,10);
    status = stack_push(&stack,-23);
    status = stack_push(&stack,79);
    status = stack_push(&stack,-91);
    status = stack_push(&stack,13);
    status = stack_push(&stack,25);             //FAIL
    status = stack_push(&stack,-42);            //FAIL

    /* display the size of the stack */
    //status = stack_size(&stack);
    printf("size of stack is (%d)\n",stack_size_value);

    /* display all elements inside the stack */
    status = stack_display(&stack);

    /* pop elements out of the stack */
    status = stack_pop(&stack);
    printf("element popped from stack is (%d)\n",stack_pop_value);
    status = stack_pop(&stack);
    printf("element popped from stack is (%d)\n",stack_pop_value);
    status = stack_pop(&stack);
    printf("element popped from stack is (%d)\n",stack_pop_value);
    status = stack_pop(&stack);
    printf("element popped from stack is (%d)\n",stack_pop_value);
    status = stack_pop(&stack);
    printf("element popped from stack is (%d)\n",stack_pop_value);
    status = stack_pop(&stack);                 //FAIL
    status = stack_pop(&stack);                 //FAIL

    /* display the size of the stack */
    //status = stack_size(&stack);
    printf("size of stack is (%d)\n",stack_size_value);

    /* display all elements inside the stack */
    status = stack_display(&stack);

    /* push/pop some elements to display the top of the stack */
    status = stack_push(&stack,25);
    //status = stack_top(&stack);
    printf("the top of the stack is (%d)\n",stack_top_value);
    status = stack_push(&stack,-42);
    //status = stack_top(&stack);
    printf("the top of the stack is (%d)\n",stack_top_value);
    //status = stack_top(&stack);
    status = stack_pop(&stack);
    printf("the top of the stack is (%d)\n",stack_top_value);
    //status = stack_top(&stack);
    status = stack_pop(&stack);

    /* display the size of the stack */
    //status = stack_size(&stack);
    printf("size of stack is (%d)\n",stack_size_value);

    /* display all elements inside the stack */
    status = stack_display(&stack);

    return 0;
}