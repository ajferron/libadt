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
    check_adt(l, index, "Index out of list range");

    frame *f = malloc(sizeof(frame));
    frame *h = l->head;

    for (int i = 0; i < index; i++)
        h = h->next;

    f->data = data;
    f->next = h->next;
    h->next = f;
    l->length++;
}

int get(list l, int index) {
    check_adt(l, index, "Index out of list range");

    frame *f = l->head;
    
    for (int i = 0; i < index && f->next != NULL; i++)
        f = f->next;

    return f->data;
}

int set(list l, int index, int data) {
    check_adt(l, index, "Index out of list range");

    frame *f = l->head;

    for (int i = 0; i < index; i++)
        f = f->next;

    f->data = data;

    return 1;
}

int find(list l, int target) {
    frame *f = l->head;

    for (int i = 0; i < l->length; i++) {
        if (f->data == target)
            return i;

        f = f->next;
    }

    return -1;
}

int cut(list l, int index) {
    check_adt(l, index, "Can not cut items from empty list");
    frame *f, *f2;
    int i, data;

    f = l->head;

    for (i = 0; (i + 1) < index; i++)
        f = f->next;

    if (l->length == 1) {
        data = f->data;
        free(f);
        l->head = NULL;

    } else if (f == l->head) {
        data = f->data;
        l->head = f->next;
        free(f);

    } else if (f == l->tail) {
        data = (f->next)->data;
        free(f->next);
        f->next = NULL;
    } else {
        data = (f->next)->data;
        f2 = (f->next)->next;
        free(f->next);
        f->next = f2;
    }

    l->length--;

    return data;
}