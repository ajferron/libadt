#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adt.h"

/* Initialize list data structure */
list create_list(void);

/* Add item to end of list */
void list_append(list, void *data);

/* Return the value at an index */
void* list_get(list, int index);

/* Insert a value at the index provided, shifting all succeeding values */
void list_insert(list, int index, void *data);

/* Set the value of an index */
void list_replace(list, int index, void *data);

/* Return the index of the first occurrence of a value or -1 if unfound */
int list_find(list, void *target);

/* Remove a index and return it's value */
void* list_cut(list, int);

/* Return the number of integers in the list if it is initialized and -1 otherwise  */
int list_len(list);

/* Free all memory allocated to the data structure */
void free_list(list);

#endif
