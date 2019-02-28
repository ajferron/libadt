#ifndef _QUE_H_
#define _QUE_H_

#include "libadt.h"

// Initialize que data structure (FIFO).
que Que(void);

// Add item to top of que.
void enque(que, int32_t);

// Remove and return bottom item in que.
int32_t deque(que);

#endif
