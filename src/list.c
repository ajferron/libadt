#include "adt.h"
#include "que.h"

list List(void) {
    stack l = malloc(sizeof(adt));
    l->head = l->tail = NULL;
    l->length = 0;
    return l;
}

void add(list l, int32_t data) {
    enque(l, data);
}

int32_t get(list l, int index) {
    frame *f = l->head;
    
    for (int i = 0; i <= index; i++)
        f = f->next;

    return f->data;
}

int set(list l, int index, int32_t data) {
    if (index > length(l))
        return 0;

    frame *f = l->head;

    for (int i = 0; i <= index; i++)
        f = f->next;

    f->data = data;

    return 1;
}

int find(list l, int32_t target) {
    frame *f = l->head;

    for (int i = 0; i < length(l); i++) {
        if (f->data == target)
            return i;

        f = f->next;
    }

    return -1;
}

int32_t delete(list l, int index) {
    frame* f = l->head;

    for (int i = 0; i < index; i++)
        f = f->next;


    int data = (f->next)->data;
    frame *f2 = (f->next)->next;
    free(f->next);
    f->next = f2;

    return data;
}