#ifndef _LIBADT_H_
#define _LIBADT_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct frame {
    int data;
    struct frame *next;
};

typedef struct frame frame;

struct adt {
    frame *head;
    frame *tail;
    int length;
};

typedef struct adt adt, *list, *stack, *que;

// Return a pointer to an array of all items in data structure
void* to_array(adt *);

// Return a pointer to an array of the characters in the data structure seperated by an interable
char* to_string(adt *, char *iterable);

// Return the number of items in data structure
int length(adt *);

// Free data structure and all memory associated. Use List()/Stack()/Que() to re-initialize
void clear(adt *);

/* Return the head of the data structure
 * List: head = first item added
 * Stack: head = last item added
 * Que: head = first item added */
int peek(adt *);

void check_adt(adt*, int min, char* msg);

#endif
