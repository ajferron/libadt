#ifndef _QUE_H_
#define _QUE_H_

#include "adt.h"

// Initialize que data structure (FIFO).
que init_que(void);

// Add item to top of que.
void enque(que, int data);

// Remove and return bottom item in que.
int deque(que);

#endif
