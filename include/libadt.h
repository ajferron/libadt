#ifndef _LIBADT_H_
#define _LIBADT_H_

#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "que.h"

struct frame {
    int32_t *data;
    struct frame *next;
};

typedef struct frame frame;

struct adt {
    int length;
    frame *head;
    frame *tail;
    int32_t **map;
};

typedef struct adt adt, *list, *stack, *que;

// Return a pointer to an array with all items in data structure
int32_t* toArray(adt *);

// Return 1 if length is 0, and 0 if length is any other value
int isEmpty(adt *);

// Return the number of items in data structure
int length(adt *);

// Free all memory associated with data structure. Use List()/Stack()/Que() to re-initialize
void clear(adt *);

/* Return the head of the data structure
 * List: returns first item added
 * Stack: returns last item added
 * Que: returns first item added */
int32_t peek(adt *);

#endif
