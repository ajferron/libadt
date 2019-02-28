#include "libadt.h"

#ifndef _QUE_H_
#define _QUE_H_

// Return pointer to memory allocation for que (struct adt)
que Que(void);

// Add item to top of que
void enque(que, void*);

// Remove and return bottom (oldest) item in que
int* deque(que);

#endif
