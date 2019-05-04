#ifndef _LIBADT_H_
#define _LIBADT_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

struct adt {
    node *head;
    node *tail;
    int length;
};

typedef struct adt adt, *list, *stack, *que, *set;

/* Return a pointer to an array of all integers in the data structure */
void* adt_array(adt *);

/* Return a pointer to an array of the characters in the data structure seperated by an interable */
char* adt_string(adt *, char *iterable);

/* Return 1 if the adt has no nodes and 0 otherwise */
int adt_empty(adt *);

/* Free all memory allocated to data structure. Use init_list()/init_stack()/init_que() to re-initialize */
void adt_clear(adt *);

#endif
