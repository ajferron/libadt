#include "adt.h"

list init_list(void) {
    list l = malloc(sizeof(adt));
    l->head = l->tail = NULL;
    l->length = 0;
    return l;
}

void add(list l, int data) {
    node *n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (l->tail != NULL)
        l->tail->next = n;

    l->tail = n;
    l->length++;

    if (l->head == NULL)
        l->head = l->tail;
}

void insert(list l, int index, int data) {
    check_adt(l, index, "Index out of list range");

    node *n = malloc(sizeof(node));
    node *h = l->head;

    for (int i = 0; i < index; i++)
        h = h->next;

    n->data = data;
    n->next = h->next;
    h->next = n;
    l->length++;
}

int get(list l, int index) {
    node *n = l->head;
    
    for (int i = 0; i < index && n->next != NULL; i++)
        n = n->next;

    return n->data;
}

int set(list l, int index, int data) {
    node *n = l->head;

    for (int i = 0; i < index; i++)
        n = n->next;

    n->data = data;

    return 1;
}

int find(list l, int target) {
    node *n = l->head;

    for (int i = 0; i < l->length; i++) {
        if (n->data == target)
            return i;

        n = n->next;
    }

    return -1;
}

int cut(list l, int index) {
    node *n, *f2;
    int i, data;

    n = l->head;

    for (i = 0; (i + 1) < index; i++)
        n = n->next;

    if (l->length == 1) {
        data = n->data;
        free(n);
        l->head = NULL;

    } else if (n == l->head) {
        data = n->data;
        l->head = n->next;
        free(n);

    } else if (n == l->tail) {
        data = (n->next)->data;
        free(n->next);
        n->next = NULL;
    } else {
        data = (n->next)->data;
        f2 = (n->next)->next;
        free(n->next);
        n->next = f2;
    }

    l->length--;

    return data;
}