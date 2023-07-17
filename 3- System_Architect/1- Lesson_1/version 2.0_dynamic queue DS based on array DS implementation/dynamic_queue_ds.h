/*
 =========================================================================================
 Name        : dynamic_queue_ds.h
 Author      : Mohamed Ashraf El-Sayed
 Version     : 2.0.0
 Copyright   : Your copyright notice
 date        : Thu, Jun 15 2023
 time        :
 Description : Implementation of dynamic queue DS based on array DS , Ansi-style
 =========================================================================================
*/

#ifndef _DYNAMIC_QUEUE_DS_H_
#define _DYNAMIC_QUEUE_DS_H_
/* ----------------------------------------------------------------------------------- */
/* ------------------Includes section------------------- */
#include "Platforms_Types.h"
#include "std_libraries.h"
#include "dynamic_queue_ds_cfg.h"


/* ----------------------------------------------------------------------------------- */
/* -----user_defined data type declaration section------ */

typedef struct{
    sint32 queue_front;                          /* points to the the first element in the queue */
    sint32 queue_rear;                           /* points to the the last element in the queue */
    void **data;                                 /* pointer points to array of pointers allocated dynamically in the heap */
}Squeue_ds_t;

typedef enum{
    queue_operation_fail = 0,                    /* queue operation failed */
    queue_operation_success,                     /* queue operation performed successfully */
    queue_null_pointer                           /* NULL pointer passed to the function */
}queue_status_t;

typedef enum{
    queue_empty = 0,                             /* queue is empty */
    queue_full,                                  /* queue is full */
    queue_space                                  /* queue is neither full nor empty */
}queue_state_t;


/* ----------------------------------------------------------------------------------- */
/* -------------------Global section-------------------- */
extern Squeue_ds_t *queue;                       /* pointer points to the queue created in heap */
extern queue_status_t status;                    /* holds the status of the performed operation */

extern void *dequeue_value;                      /* pointer points to the element removed from the queue */
extern void *queue_front_value;                  /* pointer points to the first element in the queue */
extern void *queue_rear_value;                   /* pointer points to the last element in the queue */
extern uint32 queue_max_size_value;              /* holds the maximum number of elements inside the queue */
extern uint32 queue_size_value;                  /* holds the number of elements inside the queue */


/* ----------------------------------------------------------------------------------- */
/* ------------functions declaration section------------ */

/**
  *  @brief   allocate the queue dynamically in heap based on array allocated in heap
  *  @param   my_queue  pointer to the allocated queue passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_fail)      when the opertion fail
  *                     (queue_operation_success)   when the operation is performed successfully
  */
queue_status_t queue_init(Squeue_ds_t *my_queue);

/* ----------------------------------------------------- */

/**
  *  @brief   insert the element into the queue
  *  @param   my_queue  pointer to the allocated queue passed by reference
  *  @param   ptr_value pointer to the element you want to insert into the queue
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_fail)      when the opertion fail
  *                     (queue_operation_success)   when the operation is performed successfully
  *                     (queue_null_pointer)        when NULL pointer is passed to the function
  */
queue_status_t enqueue(Squeue_ds_t *my_queue ,void *ptr_value);

/* ----------------------------------------------------- */

/**
  *  @brief   remove elements from the queue
  *  @param   my_queue  pointer to the allocated queue passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_fail)      when the opertion fail
  *                     (queue_operation_success)   when the operation is performed successfully
  *                     (queue_null_pointer)        when NULL pointer is passed to the function
  */
queue_status_t dequeue(Squeue_ds_t *my_queue);

/* ----------------------------------------------------- */

/**
  *  @brief   update the queue front
  *  @param   my_queue  pointer to the allocated queue passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_fail)      when the opertion fail
  *                     (queue_operation_success)   when the operation is performed successfully
  *                     (queue_null_pointer)        when NULL pointer is passed to the function
  */
queue_status_t queue_front_update(Squeue_ds_t *my_queue);

/* ----------------------------------------------------- */

/**
  *  @brief   update the queue rear
  *  @param   my_queue  pointer to the allocated queue passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_fail)      when the opertion fail
  *                     (queue_operation_success)   when the operation is performed successfully
  *                     (queue_null_pointer)        when NULL pointer is passed to the function
  */
queue_status_t queue_rear_update(Squeue_ds_t *my_queue);

/* ----------------------------------------------------- */

/**
  *  @brief   destroy the queue by freeing the allocated memories in heap
  *  @param   my_queue  pointer to the queue that passed by reference
  *  @retval  l_status  holds the status of the performed operation
  *                     (queue_operation_success)   when the operation is performed successfully
  *                     (queue_null_pointer)        when NULL pointer is passed to the function
  */
queue_status_t queue_destroy(Squeue_ds_t *my_queue);

/* ----------------------------------------------------------------------------------- */
#endif //_DYNAMIC_QUEUE_DS_H_