#include "adt.h"

queue init_queue(void) {
    queue q = malloc(sizeof(adt));
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;

    return q;
}

void enqueue(queue q, int data) {
    node *n;
    
    n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    if (q->tail != NULL)
        q->tail->next = n;

    q->tail = n;
    q->length++;

    if (q->head == NULL)
        q->head = q->tail;
}

int dequeue(queue q) {
    node *n;
    int data;
    
    n = q->head;
    q->head = n->next;
    data = n->data;
    q->length--;
    free(n);

    return data;
}

int queue_head(queue q) {
    return q->head->data;
}

int queue_tail(queue q) {
    return q->tail->data;
}

void free_queue(queue q) {
    node *n;

    if (q->length) {
        n = q->head;

        while (q->head != NULL) {
            n = n->next;
            free(q->head);
            q->head = n;
        }

        q->head = NULL;
        q->tail = NULL;
        q->length = 0;
    }

    free(q);
}