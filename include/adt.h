#ifndef _ADT_H_
#define _ADT_H_

struct node {
    int data;
    struct node *next;
};

typedef struct node node, element, frame;

struct multiset {
    element *head;
    element *tail;
    int cardinality;
};

typedef struct multiset *multiset;

struct list {
    node *front;
    node *end;
    int length;
};

typedef struct list *list;

struct queue {
    frame *head;
    frame *tail;
};

typedef struct queue *queue;

struct stack {
    frame *head;
};

typedef struct stack *stack;

#endif