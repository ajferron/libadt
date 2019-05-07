#include "stack.h"

stack create_stack(void) {
    stack s;
    
    s = malloc(sizeof(stack));
    s->head = NULL;

    return s;
}

void stack_push(stack s, int data) {
    frame *n;
    
    n = malloc(sizeof(frame));
    n->data = data;
    n->next = s->head;
    s->head = n;
}

int stack_pop(stack s) {
    frame *n;
    int data;

    n = s->head;
    s->head = n->next;
    data = n->data;
    free(n);

    return data;
}

int stack_peek(stack s) {
    return s->head->data;
}

int stack_empty(stack s) {
    if (s->head == NULL)
        return 1;

    return 0;
}

void free_stack(stack s) {
    frame *n;

    if (s->head != NULL) {
        n = s->head;

        while (s->head != NULL) {
            n = n->next;
            free(s->head);
            s->head = n;
        }

        s->head = NULL;
    }

    free(s);
}