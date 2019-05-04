#include "adt.h"

list init_list(void) {
    list l;
    
    l = malloc(sizeof(adt));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;

    return l;
}

void append(list l, int data) {
    node *n;

    n = malloc(sizeof(node));

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
    node *n, *h;
    int i;

    n = malloc(sizeof(node));
    h = l->head;

    for (i = 0; i < index; i++)
        h = h->next;

    n->data = data;
    n->next = h->next;
    h->next = n;
    l->length++;
}

int get(list l, int index) {
    node *n;
    int  i;
    
    n = l->head;
    
    for (i = 0; i < index && n->next != NULL; i++)
        n = n->next;

    return n->data;
}

int replace(list l, int index, int data) {
    node *n;
    int i;
    
    if (l->length < index)
        return 0;

    n = l->head;

    for (i = 0; i < index; i++)
        n = n->next;

    n->data = data;

    return 1;
}

int find(list l, int target) {
    node *n;
    int i;

    n = l->head;

    for (i = 0; i < l->length; i++) {
        if (n->data == target)
            return i;

        n = n->next;
    }

    return -1;
}

int cut(list l, int index) {
    node *n, *n2;
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
        n2 = (n->next)->next;
        free(n->next);
        n->next = n2;
    }

    l->length--;

    return data;
}

int length(list lst) {
    if (lst != NULL)
        return lst->length;

    return -1;
}