#ifndef _LIBADT_H_
#define _LIBADT_H_

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct frame {
    int32_t data;
    struct frame *next;
};

typedef struct frame frame;

struct adt {
    int length;
    frame *head;
    frame *tail;
};

typedef struct adt adt, *list, *stack, *que;

// Return a pointer to an array of all items in data structure.
void* toArray(adt *);

// Return a pointer to an array of characters in data structure.
char* toString(adt *, char *);

// Return the number of items in data structure.
int length(adt *);

// Free data structure and all memory associated. Use List()/Stack()/Que() to re-initialize.
void clear(adt *);

/* Return the head of the data structure
 * List: head = first item added
 * Stack: head = last item added
 * Que: head = first item added */
int32_t peek(adt *);

#endif
