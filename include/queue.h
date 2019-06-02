#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include "adt.h"

/* Initialize que data structure (FIFO) */
queue create_queue(void);

/* Add integer to top of que */
void enqueue(queue, void *data);

/* Remove and return bottom integer in que */
void* dequeue(queue);

/* Return the integer at the front of the que (first added) */
void* queue_head(queue);

/* Return the integer at the end of the que (last added) */
void* queue_tail(queue);

/* Return 1 if the queue is empty and 0 otherwise */
int queue_empty(queue);

/* Free all memory allocated to the data structure */
void free_queue(queue);

#endif
