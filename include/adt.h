#ifndef _ADT_H_
#define _ADT_H_

struct node {
    void *data;
    struct node *next;
};

typedef struct node node;

struct list {
    node *front;
    node *end;
    int length;
};

typedef struct list *list;

struct queue {
    node *head;
    node *tail;
};

typedef struct queue *queue;

struct stack {
    node *head;
};

typedef struct stack *stack;

struct multiset {
    node *head;
    node *tail;
    int cardinality;
};

typedef struct multiset *multiset;

#endif