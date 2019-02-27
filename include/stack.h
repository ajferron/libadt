#include "libadt.h"

#ifndef _STACK_H_
#define _STACK_H_

// Create memory allocation for stack (struct adt)
stack Stack(void);

// Add item to the top of stack
void push(stack, void *);

// Remove and return the last item added
void* pop(stack);

#endif
