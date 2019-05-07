#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

struct list {
    node *front;
    node *end;
    int length;
};

typedef struct list *list;

/* Initialize list data structure */
list create_list(void);

/* Add item to end of list */
void list_append(list, int data);

/* Insert a value after the index provided */
void list_insert(list, int index, int data);

/* Return the value at an index */
int list_get(list, int index);

/* Return the index of the first occurrence of a value or -1 if unfound */
int list_find(list, int data);

/* Set the value of an index */
void list_replace(list, int index, int data);

/* Remove a index and return it's value */
int list_cut(list, int);

/* Return the number of integers in the list if it is initialized and -1 otherwise  */
int list_len(list);

/* Return a pointer to an array of all integers in the data structure */
void* list_array(list);

/* Return a pointer to an array of the characters in the data structure seperated by an interable */
char* list_string(list, char *iterable, size_t iter_len);

/* Free all memory allocated to the data structure */
void free_list(list);

#endif
