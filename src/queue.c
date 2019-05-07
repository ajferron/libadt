#include "queue.h"

queue init_queue(void) {
    queue q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(queue q, int data) {
    frame *f;
    
    f = malloc(sizeof(frame));
    f->data = data;
    f->next = NULL;

    if (q->tail != NULL)
        q->tail->next = f;

    q->tail = f;

    if (q->head == NULL)
        q->head = q->tail;
}

int dequeue(queue q) {
    frame *f;
    int data;
    
    f = q->head;
    q->head = f->next;
    data = f->data;
    free(f);

    return data;
}

int queue_head(queue q) {
    return q->head->data;
}

int queue_tail(queue q) {
    return q->tail->data;
}

int queue_empty(queue q) {
    if (q->head == NULL)
        return 1;

    return 0;
}

void free_queue(queue q) {
    frame *f;

    if (q->head != NULL) {
        f = q->head;

        while (q->head != NULL) {
            f = f->next;
            free(q->head);
            q->head = f;
        }

        q->head = NULL;
        q->tail = NULL;
    }

    free(q);
}