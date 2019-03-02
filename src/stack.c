#include "adt.h"

stack Stack(void) {
    stack s = malloc(sizeof(adt));
    s->head = s->tail = NULL;
    s->map = NULL;
    s->length = 0;
    return s;
}

void push(stack s, int32_t d) {
    frame *f = malloc(sizeof(frame));

    f->data = d;
    f->next = s->head;
    s->head = f;
    s->length++;
}

int32_t pop(stack s) {
    frame *f = s->head;
    s->head = f->next;
    int d = f->data;
    s->length--;
    free(f);

    return d;
}