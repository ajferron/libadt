#include "adt.h"

que init_que(void) {
    que q = malloc(sizeof(adt));
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
}

void enque(que q, int data) {
    node *n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (q->tail != NULL)
        q->tail->next = n;

    q->tail = n;
    q->length++;

    if (q->head == NULL)
        q->head = q->tail;
}

int deque(que q) {
    node *n = q->head;
    q->head = n->next;
    
    int data = n->data;
    q->length--;
    free(n);

    return data;
}