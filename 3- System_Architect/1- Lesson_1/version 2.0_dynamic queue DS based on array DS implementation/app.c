/*
 =========================================================================================
 Name        : app.c
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Thu, Jun 15 2023
 time        :
 Description : Implementation of dynamic queue DS based on array DS , Ansi-style
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
uint32 var_4 = 37;


/* ----------------------------------------------------------------------------------- */

int main()
{
    /* insert the number of elements in queue by (3) */
    /* example for queue of 3 elements */

    /* initialize the queue */
    status = queue_init(queue);

    /* insert var_1 into the queue */
    status = enqueue(queue,&var_1);

    /* var_1 is now the queue front and rear */
    printf("the queue front is (%d)\n",*(sint32 *)queue_front_value);
    printf("the queue rear is  (%d)\n",*(sint32 *)queue_rear_value);


    /* insert var_2 into the queue */
    status = enqueue(queue,&var_2);

    /* var_1 is now the queue front and var_2 is now the queue rear */
    printf("the queue front is (%d)\n",*(sint32 *)queue_front_value);
    printf("the queue rear is  (%.2f)\n",*(float32 *)queue_rear_value);

    /* insert var_3 into the queue */
    status = enqueue(queue,&var_3);

    /* var_1 is now the queue front and var_3 is now the queue rear */
    printf("the queue front is (%d)\n",*(sint32 *)queue_front_value);
    printf("the queue rear is  (%c)\n",*(uint8 *)queue_rear_value);

    /* display the size of the queue */
    printf("size of queue is (%d)\n",queue_size_value);

    /* remove var_1 from the queue */
    status = dequeue(queue);
    printf("element removed from queue is (%d)\n",*(sint32 *)dequeue_value);

    /* var_2 is now the queue front and var_3 is now the queue rear */
    printf("the queue front is (%.2f)\n",*(float32 *)queue_front_value);
    printf("the queue rear is  (%c)\n",*(uint8 *)queue_rear_value);

    /* insert var_4 into the queue */
    status = enqueue(queue,&var_4);

    /* var_2 is now the queue front and var_4 is now the queue rear */
    printf("the queue front is (%.2f)\n",*(float32 *)queue_front_value);
    printf("the queue rear is  (%d)\n",*(uint32 *)queue_rear_value);

    /* remove var_2 from the queue */
    status = dequeue(queue);
    printf("element removed from queue is (%.2f)\n",*(float32 *)dequeue_value);

    /* var_3 is now the queue front and var_4 is now the queue rear */
    printf("the queue front is (%c)\n",*(uint8 *)queue_front_value);
    printf("the queue rear is  (%d)\n",*(uint32 *)queue_rear_value);

    /* remove var_3 from the queue */
    status = dequeue(queue);
    printf("element removed from queue is (%c)\n",*(uint8 *)dequeue_value);

    /* var_4 is now the queue front and rear */
    printf("the queue front is (%d)\n",*(uint32 *)queue_front_value);
    printf("the queue rear is  (%d)\n",*(uint32 *)queue_rear_value);

    /* remove var_4 from the queue */
    status = dequeue(queue);
    printf("element removed from queue is (%d)\n",*(uint32 *)dequeue_value);

    /* queue is now empty */

    /* display the size of the queue */
    printf("size of queue is (%d)\n",queue_size_value);

    /* try to dequeue from empty queue */
    status = dequeue(queue);

    /* try to display the queue front and rear from empty queue */
    status = queue_front_update(queue);
    status = queue_rear_update(queue);

    /* destory the queue */
    status = queue_destroy(queue);

    return 0;
}