#ifndef _LIST_H_
#define _LIST_H_

#include "adt.h"

/* Initialize list data structure */
list init_list(void);

/* Add item to end of list */
void list_append(list, int data);

/* Insert a value after the index provided */
void list_insert(list, int index, int data);

/* Return the value at an index */
int list_get(list, int index);

/* Return the index of the first occurrence of a value or -1 if unfound */
int list_find(list, int data);

/* Set the value of an index */
int list_replace(list, int index, int data);

/* Remove a index and return it's value */
int list_cut(list, int);

/* Return the number of integers in the list if it is initialized and -1 otherwise  */
int list_len(list);

#endif
