#ifndef _LIST_H_
#define _LIST_H_

#include "adt.h"

/* Initialize list data structure */
list init_list(void);

/* Add item to end of list */
void append(list, int data);

/* Insert a value before the index provided */
void insert(list, int index, int data);

/* Return the value at an index */
int get(list, int index);

/* Return the index of the first/last occurrence of a value or -1 if unfound */
int find(list, int data);

/* Set the value at an index. Return 1 if successful and 0 otherwise */
int replace(list, int index, int data);

/* Remove a index and return it's value */
int cut(list, int);

/* Return the number of integers in the list if it is initialized and -1 otherwise  */
int length(list);

#endif
