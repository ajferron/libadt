#include "adt.h"

stack Stack(void) {
    stack s = malloc(sizeof(adt));
    s->head = s->tail = NULL;
    s->length = 0;
    return s;
}

void push(stack s, int32_t data) {
    frame *f = malloc(sizeof(frame));

    f->data = data;
    f->next = s->head;
    s->head = f;
    s->length++;
}

int32_t pop(stack s) {
    frame *f = s->head;
    s->head = f->next;

    int32_t data = f->data;
    s->length--;
    free(f);

    return data;
}