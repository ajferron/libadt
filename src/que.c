#include "adt.h"

que Que(void) {
    que q = malloc(sizeof(adt));
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
}

void enque(que q, int32_t d) {
    frame *tail = q->tail;
    frame *f = malloc(sizeof(frame));

    f->data = d;
    f->next = NULL;

    if (tail != NULL)
        q->tail->next = f;

    q->tail = f;
    q->length++;

    if (q->head == NULL)
        q->head = tail;
}

int32_t deque(que q) {
    frame *f = q->head;
    q->head = f->next;
    
    int32_t data = f->data;
    q->length--;
    free(f);

    return data;
}