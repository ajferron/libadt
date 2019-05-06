#ifndef _STACK_H_
#define _STACK_H_

#include "adt.h"

/* Initialize stack data structure (LIFO) */
stack init_stack(void);

/* Add integer to the top of stack */
void stack_push(stack, int data);

/* Remove and return the last integer added */
int stack_pop(stack);

/* Return the head of the stack (last added) */
int stack_peek(stack);

#endif
