#include "adt.h"

list init_list(void) {
    list l;
    
    l = malloc(sizeof(adt));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;

    return l;
}

void list_append(list l, int data) {
    node *n;

    n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (l->tail != NULL)
        l->tail->next = n;

    l->tail = n;
        
    if (l->head == NULL)
        l->head = l->tail;

    l->length++;
}

void list_insert(list l, int index, int data) {
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

int list_get(list l, int index) {
    node *n;
    int  i;
    
    n = l->head;
    
    for (i = 0; i < index && n->next != NULL; i++)
        n = n->next;

    return n->data;
}

void list_replace(list l, int index, int data) {
    node *n;
    int i;

    n = l->head;

    for (i = 0; i < index; i++)
        n = n->next;

    n->data = data;
}

int list_find(list l, int target) {
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

int list_cut(list l, int index) {
    node *n, *n1;
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

void* list_array(list l) {
    node *n;
    int *a, i;

    if (!l->length)
        return NULL;

    n = l->head;

    a = malloc(sizeof(int) * l->length);

    for (i = 0; i < l->length; i++) {
        a[i] = n->data;
        n = n->next;
    }
    
    return a;
}

char* list_string(list l, char* iterable, size_t iter_len) {
    node *n;
    int len, i;
    char *s;
    
    if (!l->length)
        return NULL;

    len = l->length + (iter_len * l->length);
    s = malloc((sizeof(char)) * len);
    n = l->head;

    for (i = 0; i < len; i += iter_len + 1) {
        sprintf(&s[i], "%c", (char) n->data);

        if (i + iter_len + 1 < len)
            strcat(s, iterable);

        n = n->next;
    }

    return s;
}

void free_list(list l) {
    node *n;

    if (l->length) {
        n = l->head;

        while (l->head != NULL) {
            n = n->next;
            free(l->head);
            l->head = n;
        }

        l->head = NULL;
        l->tail = NULL;
        l->length = 0;
    }

    free(l);
}