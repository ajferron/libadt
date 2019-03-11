#include "adt.h"

stack init_stack(void) {
    stack s = malloc(sizeof(adt));
    s->head = s->tail = NULL;
    s->length = 0;
    return s;
}

void push(stack s, int data) {
    frame *f = malloc(sizeof(frame));

    f->data = data;
    f->next = s->head;
    s->head = f;
    s->length++;
}

int pop(stack s) {
    check_adt(s, "Can not pop items from empty stack");

    frame *f = s->head;
    s->head = f->next;

    int data = f->data;
    s->length--;
    free(f);

    return data;
}