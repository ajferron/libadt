#ifndef _LIST_H_
#define _LIST_H_

#include "adt.h"

// Initialize list data structure.
list List(void);

// Add item to end of list.
void add(list, int32_t);

// Insert a value before the index provided.
void insert(list, int, int32_t);

// Return the value at an index.
int32_t get(list, int);

// Return the index of the first/last occurrence of a value or -1 if unfound.
int find(list, int32_t);

// Set the value at an index. Return 1 if successful and 0 otherwise.
int set(list, int, int32_t);

// Remove a index and return it's value.
int32_t delete(list, int);

#endif
