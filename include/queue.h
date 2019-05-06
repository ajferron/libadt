#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "adt.h"

/* Initialize que data structure (FIFO) */
que init_que(void);

/* Add integer to top of que */
void enqueue(que, int data);

/* Remove and return bottom integer in que */
int dequeue(que);

/* Return the integer at the front of the que (first added) */
int queue_head(que);

/* Return the integer at the end of the que (last added) */
int queue_tail(que);

#endif
