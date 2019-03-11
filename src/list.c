#include "adt.h"

list init_list(void) {
    list l = malloc(sizeof(adt));
    l->head = l->tail = NULL;
    l->length = 0;
    return l;
}

void add(list l, int data) {
    frame *f = malloc(sizeof(frame));

    f->data = data;
    f->next = NULL;

    if (l->tail != NULL)
        l->tail->next = f;

    l->tail = f;
    l->length++;

    if (l->head == NULL)
        l->head = l->tail;
}

void insert(list l, int index, int data) {
    check_adt(l, "Index out of list range");

    frame *f = malloc(sizeof(frame));
    frame *h = l->head;

    for (int i = 0; i <= index; i++)
        h = h->next;

    f->data = data;
    f->next = h->next;
    h->next = f;
}

int get(list l, int index) {
    check_adt(l, "Index out of list range");

    frame *f = l->head;
    
    for (int i = 0; i < index && f->next != NULL; i++)
        f = f->next;

    return f->data;
}

int set(list l, int index, int data) {
    check_adt(l, "Index out of list range");

    frame *f = l->head;

    for (int i = 0; i < index; i++)
        f = f->next;

    f->data = data;

    return 1;
}

int find(list l, int target) {
    frame *f = l->head;

    for (int i = 0; i < length(l); i++) {
        if (f->data == target)
            return i;

        f = f->next;
    }

    return -1;
}

int cut(list l, int index) {
    check_adt(l, "Can not cut items from empty list");

    frame* f = l->head;

    for (int i = 0; i < index; i++)
        f = f->next;


    int data = (f->next)->data;
    frame *f2 = (f->next)->next;
    free(f->next);
    f->next = f2;

    return data;
}