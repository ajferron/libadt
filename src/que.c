#include "adt.h"

que init_que(void) {
    que q = malloc(sizeof(adt));
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
}

void enque(que q, int data) {
    frame *f = malloc(sizeof(frame));

    f->data = data;
    f->next = NULL;

    if (q->tail != NULL)
        q->tail->next = f;

    q->tail = f;
    q->length++;

    if (q->head == NULL)
        q->head = q->tail;
}

int deque(que q) {
    check_adt(q, 0, "Can not deque items from empty que");
    frame *f = q->head;
    q->head = f->next;
    
    int data = f->data;
    q->length--;
    free(f);

    return data;
}