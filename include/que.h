#ifndef _QUE_H_
#define _QUE_H_

#include "libadt.h"

// Return pointer to memory allocation for que (struct adt)
que Que(void);

// Add item to top of que
void enque(que, int32_t);

// Remove and return bottom (oldest) item in que
int* deque(que);

#endif
