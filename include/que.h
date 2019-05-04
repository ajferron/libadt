#ifndef _QUE_H_
#define _QUE_H_

#include "adt.h"

/* Initialize que data structure (FIFO) */
que init_que(void);

/* Add integer to top of que */
void enque(que, int data);

/* Remove and return bottom integer in que */
int deque(que);

#endif
