#ifndef _LIST_H_
#define _LIST_H_

#include "adt.h"

enum occurrence {first, last};

// Initialize list data structure.
list List(void);

// Add item to end of list.
void add(list, int32_t);

// Swap the values of 2 indexes.
void swap(list, int, int);

// Insert a value before the index provided.
void insert(list, int, int32_t);

// Return the value at an index.
int32_t get(list, int);

// Return the index of the first/last occurrence of a value or -1 if unfound.
int find(list, int32_t, occurrence);

// Set the value at an index.
int set(list, int, int32_t);

// Remove a index and return it's value.
int32_t remove(list, int);

#endif
