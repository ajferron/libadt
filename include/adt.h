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

typedef struct adt adt, *list, *stack, *queue, *set;


#endif
