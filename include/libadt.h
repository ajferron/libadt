#ifndef _LIBADT_H_
#define _LIBADT_H_

struct frame {
    int *data;
    struct frame *next;
};

typedef struct frame frame;

struct adt {
    int length;
    frame *head;
    frame *tail;
    int **map;
};

typedef struct adt adt, *list, *stack, *que;

/* Abstract Function Prototypes */

void *toArray(adt *);

int isEmpty(adt *);

int length(adt *);

void clear(adt *);

void *peek(adt *);

#endif
