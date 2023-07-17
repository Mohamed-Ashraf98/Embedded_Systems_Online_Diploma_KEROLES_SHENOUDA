/*
 =========================================================================================
 Name        : dynamic_queue_ds.c
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
#include "dynamic_queue_ds.h"


/* ----------------------------------------------------------------------------------- */
/* -----user_defined data type definition section------- */
Squeue_ds_t *queue = NULL;                  /* pointer points to the queue created in heap */
queue_status_t status = ZERO_INIT;          /* holds the status of the performed operation */


/* ----------------------------------------------------------------------------------- */
/* -------------------Global section-------------------- */
void *dequeue_value = NULL;                 /* pointer points to the element removed from the queue */
void *queue_front_value = NULL;             /* pointer points to the first element in the queue */
void *queue_rear_value = NULL;              /* pointer points to the last element in the queue */
uint32 queue_max_size_value = ZERO_INIT;    /* holds the maximum number of elements inside the queue */
uint32 queue_size_value = ZERO_INIT;        /* holds the number of elements inside the queue */


/* ----------------------------------------------------------------------------------- */
/* ------------functions definition section------------- */

/**
  *  @brief   check if queue is empty or not to avoid queue underflow
  *  @retval  l_state   holds the status of the queue
  *                     (queue_empty)   when the queue is empty
  *                     (queue_space)   when the queue is not empty
  */
static queue_status_t queue_is_empty()
{
    /* create a locatl variable to hold the state of the queue */
    queue_status_t l_state = ZERO_INIT;

    /* check if the queue is empty or not */
    if( queue_size_value == 0 )
    {
        /* queue is empty */
        l_state = queue_empty;
    }
    else
    {
        /* queue is not empty */
        l_state = queue_space;
    }

    return l_state;
}

/* ----------------------------------------------------- */

/**
  *  @brief   check if queue is full or not to avoid queue overflow
  *  @retval  l_state   holds the status of the queue
  *                     (queue_full)    when the queue is full
  *                     (queue_space)   when the queue is not full
  */
static queue_status_t queue_is_full()
{
    /* create a locatl variable to hold the state of the queue */
    queue_status_t l_state = ZERO_INIT;

    /* check if the queue is full or not */
    if( queue_size_value == queue_max_size_value )
    {
        /* queue is full */
        l_state = queue_full;
    }
    else
    {
        /* queue is not full */
        l_state = queue_space;
    }

    return l_state;
}

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t queue_init(Squeue_ds_t *my_queue)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;

    /* allocate the queue in the heap */
    my_queue = (Squeue_ds_t *)malloc( sizeof(Squeue_ds_t) );

    /* check if the queue is allocated in heap or not */
    if(my_queue == NULL)
    {
        /* queue couldnt't be allocated in heap */

        /* queue operation failed */
        l_status = queue_operation_fail;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : queue couldn't be allocated in the heap\n");
        #endif
    }
    else
    {
        /* queue is allocated in heap successfully */

        /* queue operation performed successfully */
        l_status = queue_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("queue is allocated in heap successfully\n");
        #endif

        /* enter the max size of queue */
        printf("Enter the max size of queue :  ");
        scanf("%d",&queue_max_size_value);

        /* allocate the array of pointers according to the size entered */
        my_queue->data = (void **)malloc(queue_max_size_value * sizeof(void *));

        /* check if the array is allocated in heap or not */
        if(my_queue->data == NULL)
        {
            /* the array couldn't be allocated in heap */

            /* free the allocated memory pointed by my_queue in heap */
            free(my_queue);

            /* queue operation failed */
            l_status = queue_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : the array of pointers couldn't be allocated in the heap\n");
            #endif
        }
        else
        {
            /* the array of pointers is allocated in heap successfully */

            /* initialize the queue */

            /* initialize the queue_front with -1 */
            my_queue->queue_front = -1;
            /* initialize the queue_rear with -1 */
            my_queue->queue_rear = -1;
            /* number of elements inside the queue is zero */
            queue_size_value = ZERO_INIT;

            /* update the queue to point to the allocated memory in heap */
            queue = my_queue;

            /* queue operation performed successfully */
            l_status = queue_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("queue of (%d) elements is allocated in the heap successfully\n",queue_max_size_value);
            #endif
        }
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t enqueue(Squeue_ds_t *my_queue ,void *ptr_value)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_queue == NULL || ptr_value == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = queue_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the queue is full or not to avoid queue overflow */
        if(queue_is_full() == queue_full)
        {
            /* queue is full */

            /* pointer points to the element removed from the queue */
            dequeue_value = NULL; 

            /* queue operation failed */
            l_status = queue_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : queue is full, can't insert any element to the queue\n");
            #endif
        }
        else
        {
            /* queue is not full */

            /* increment the queue_rear to point to the next location */
            (my_queue->queue_rear)++;

            /* check if the queue rear is equal to the max size of queue or not (circular queue) */
            if(my_queue->queue_rear == queue_max_size_value)
            {
                /* queue rear is equal to the max size of queue */

                /* force queue rear to be zero (circular queue) */
                my_queue->queue_rear = ZERO_INIT;
            }
            else{ /* nothing */ }

            /* check if the queue has zero elements or not */
            if(queue_size_value == 0)
            {
                /* queue was empty, which means queue is created and both of queue_rear and queue_front were initialized with -1 */

                /* force queue front to be zero */
                my_queue->queue_front = ZERO_INIT;
            }
            else{ /* nothing */ }

            /* insert the element into the queue */
            my_queue->data[my_queue->queue_rear] = ptr_value;

            /* update the pointer that points to the last element of the queue */
            /* pointer points to the last element in the queue */
            queue_rear_value = ptr_value;

            /* update the pointer that points to the first element of the queue */
            /* pointer points to the first element in the queue */
            queue_front_value = my_queue->data[my_queue->queue_front];

            /* update the size of queue */
            /* holds the number of elements inside the queue */
            queue_size_value++;

            /* queue operation performed successfully */
            l_status = queue_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is inserted into the queue successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t dequeue(Squeue_ds_t *my_queue)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;
    
    /* check if the address is valid or not */
    if(my_queue == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = queue_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the queue is empty or not to avoid queue underflow */
        if(queue_is_empty() == queue_empty)
        {
            /* queue is empty */

            /* pointer points to the element removed from the queue */
            dequeue_value = NULL; 

            /* queue operation failed */
            l_status = queue_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : queue is empty, can't dequeue any element from empty queue\n");
            #endif
        }
        else
        {
            /* queue is not empty */

            /* copy the value into dequeue_value before removing the element from the queue */
            /* pointer points to the element removed from the queue */
            dequeue_value = my_queue->data[my_queue->queue_front];

            /* increment the queue_front to point to the next location */
            (my_queue->queue_front)++;

            /* check if the queue front is equal to the max size of queue or not (circular queue) */
            if(my_queue->queue_front == queue_max_size_value)
            {
                /* queue front is equal to the max size of queue */

                /* force queue front to be zero (circular queue) */
                my_queue->queue_front = ZERO_INIT;
            }
            else{ /* nothing */ }

            /* check if the queue has one element or not */
            if(queue_size_value == 1)
            {
                /* queue will be empty, which means both of queue_rear and queue_front will be initialized with -1 */

                /* force queue front and rear to be -1 */
                my_queue->queue_front = -1;
                my_queue->queue_rear = -1;
            }
            else{ /* nothing */ }

            /* update the pointer that points to the first element of the queue */
            /* pointer points to the first element in the queue */
            queue_front_value = my_queue->data[my_queue->queue_front];

            /* update the pointer that points to the last element of the queue */
            /* pointer points to the last element in the queue */
            queue_rear_value = my_queue->data[my_queue->queue_rear];

            /* update the size of queue */
            /* holds the number of elements inside the queue */
            queue_size_value--;

            /* queue operation performed successfully */
            l_status = queue_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is removed from the queue successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t queue_front_update(Squeue_ds_t *my_queue)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;
    
    /* check if the address is valid or not */
    if(my_queue == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = queue_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the queue is empty or not to avoid queue underflow */
        if(queue_is_empty() == queue_empty)
        {
            /* queue is empty */

            /* pointer points to the element removed from the queue */
            dequeue_value = NULL; 

            /* queue operation failed */
            l_status = queue_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : queue is empty, can't display queue front from empty queue\n");
            #endif
        }
        else
        {
            /* queue is not empty */

            /* copy the value into queue_front_value */
            /* update the pointer that points to the first element of the queue */
            /* pointer points to the first element in the queue */
            queue_front_value = my_queue->data[my_queue->queue_front];

            /* update the pointer that points to the last element of the queue */
            /* pointer points to the last element in the queue */
            queue_rear_value = my_queue->data[my_queue->queue_rear];

            /* queue operation performed successfully */
            l_status = queue_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is copied successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t queue_rear_update(Squeue_ds_t *my_queue)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;
    
    /* check if the address is valid or not */
    if(my_queue == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = queue_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* check if the queue is empty or not to avoid queue underflow */
        if(queue_is_empty() == queue_empty)
        {
            /* queue is empty */

            /* pointer points to the element removed from the queue */
            dequeue_value = NULL; 

            /* queue operation failed */
            l_status = queue_operation_fail;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("ERROR !! : queue is empty, can't display queue rear from empty queue\n");
            #endif
        }
        else
        {
            /* queue is not empty */

            /* copy the value into queue_rear_value */
            /* update the pointer that points to the last element of the queue */
            /* pointer points to the last element in the queue */
            queue_rear_value = my_queue->data[my_queue->queue_rear];

            /* update the pointer that points to the first element of the queue */
            /* pointer points to the first element in the queue */
            queue_front_value = my_queue->data[my_queue->queue_front];

            /* queue operation performed successfully */
            l_status = queue_operation_success;

            /* debug purposes */
            #if DEBUG_ENABLE
            printf("element is copied successfully\n");
            #endif
        } 
    }

    return l_status;
}
#endif

/* ----------------------------------------------------- */

#if QUEUE_CONFIG
queue_status_t queue_destroy(Squeue_ds_t *my_queue)
{
    /* create a local variable to hold the status of the performed operation */
    queue_status_t l_status = ZERO_INIT;

    /* check if the address is valid or not */
    if(my_queue == NULL)
    {
        /* the address passed is not valid */

        /* NULL pointer passed to the function */
        l_status = queue_null_pointer;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("ERROR !! : NULL pointer is passed to the function\n");
        #endif
    }
    else
    {
        /* the address is valid */

        /* free the allocated memories from heap */
        free(my_queue->data);
        free(my_queue);

        /* initialize the pointer with NULL  to avoid dangling pointer */
        my_queue = NULL;
        queue = NULL;

        /* queue operation performed successfully */
        l_status = queue_operation_success;

        /* debug purposes */
        #if DEBUG_ENABLE
        printf("queue is deallocated from the heap successfully\n");
        #endif
    }

    return l_status;
}
#endif

/* ----------------------------------------------------------------------------------- */