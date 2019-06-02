#include "list.h"

list create_list(void) {
    list l;
    
    l = malloc(sizeof(struct list));
    l->front = NULL;
    l->end = NULL;
    l->length = 0;

    return l;
}

void list_append(list l, void *data) {
    node *n;

    n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (l->end != NULL)
        l->end->next = n;

    l->end = n;
        
    if (l->front == NULL)
        l->front = l->end;

    l->length++;
}

void* list_get(list l, int index) {
    node *n;
    int  i;
    
    n = l->front;
    
    for (i = 0; i < index; i++)
        n = n->next;

    return n->data;
}

void list_insert(list l, int index, void *data) {
    node *new, *temp;
    int i;

    new = malloc(sizeof(node));
    temp = l->front;
    new->data = data;

    if (index == 0) {
        new->next = temp;
        l->front = new;

    } else {
        for (i = 0; i < index - 1; i++)
            temp = temp->next;

        new->next = temp->next;
        temp->next = new;
    }

    l->length++;
}

void list_replace(list l, int index, void *data) {
    node *n;
    int i;

    n = l->front;

    for (i = 0; i < index; i++) {
        n = n->next;
    }

    n->data = data;
}

int list_find(list l, void *target) {
    node *n;
    int i;

    n = l->front;

    for (i = 0; i < l->length; i++) {
        if (n->data == target)
            return i;

        n = n->next;
    }

    return -1;
}

void* list_cut(list l, int index) {
    node *n, *n1;
    void* data;
    int i;

    n = l->front;

    for (i = 0; (i + 1) < index; i++)
        n = n->next;

    if (l->length == 1) {
        data = n->data;
        free(n);
        l->front = NULL;

    } else if (n == l->front) {
        data = n->data;
        l->front = n->next;
        free(n);

    } else if (n == l->end) {
        data = (n->next)->data;
        free(n->next);
        n->next = NULL;

    } else {
        data = (n->next)->data;
        n1 = (n->next)->next;
        free(n->next);
        n->next = n1;
    }

    l->length--;

    return data;
}

int list_len(list lst) {
    if (lst != NULL)
        return lst->length;

    return -1;
}

void free_list(list l) {
    node *n;

    if (l->length) {
        n = l->front;

        while (l->front != NULL) {
            n = n->next;
            free(l->front);
            l->front = n;
        }

        l->front = NULL;
        l->end = NULL;
        l->length = 0;
    }

    free(l);
}