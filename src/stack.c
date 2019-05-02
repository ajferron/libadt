#include "adt.h"

stack init_stack(void) {
    stack s = malloc(sizeof(adt));
    s->head = s->tail = NULL;
    s->length = 0;
    return s;
}

void push(stack s, int data) {
    node *n = malloc(sizeof(node));

    n->data = data;
    n->next = s->head;
    s->head = n;
    s->length++;
}

int pop(stack s) {
    check_adt(s, 0, "Can not pop items from empty stack");

    node *n = s->head;
    s->head = n->next;

    int data = n->data;
    s->length--;
    free(n);

    return data;
}