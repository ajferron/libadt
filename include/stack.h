#ifndef _STACK_H_
#define _STACK_H_

#include "adt.h"

// Initialize stack data structure (LIFO).
stack Stack(void);

// Add item to the top of stack.
void push(stack, int32_t);

// Remove and return the last item added.
int32_t pop(stack);

#endif
