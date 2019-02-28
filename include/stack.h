#ifndef _STACK_H_
#define _STACK_H_

#include "libadt.h"

// Return pointer to memory allocation for stack (struct adt)
stack Stack(void);

// Add item to the top of stack
void push(stack, int32_t);

// Remove and return the last item added
void* pop(stack);

#endif
