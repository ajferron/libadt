#include "queue.h"

queue create_queue(void) {
    queue q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(queue q, void *data) {
    node *n;
    
    n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    if (q->tail != NULL)
        q->tail->next = n;

    q->tail = n;

    if (q->head == NULL)
        q->head = q->tail;
}

void* dequeue(queue q) {
    node *n;
    void* data;
    
    n = q->head;
    q->head = n->next;
    data = n->data;
    free(n);

    return data;
}

void* queue_head(queue q) {
    return q->head->data;
}

void* queue_tail(queue q) {
    return q->tail->data;
}

int queue_empty(queue q) {
    if (q->head == NULL)
        return 1;

    return 0;
}

void free_queue(queue q) {
    node *n;

    if (q->head != NULL) {
        n = q->head;

        while (q->head != NULL) {
            n = n->next;
            free(q->head);
            q->head = n;
        }

        q->head = NULL;
        q->tail = NULL;
    }

    free(q);
}