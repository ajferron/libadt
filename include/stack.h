#ifndef _STACK_H_
#define _STACK_H_

#include "adt.h"

// Initialize stack data structure (LIFO).
stack init_stack(void);

// Add item to the top of stack.
void push(stack, int data);

// Remove and return the last item added.
int pop(stack);

#endif
