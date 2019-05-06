#include "adt.h"

void* adt_array(adt *t) {
    node *n;
    int *a, i;

    if (!t->length)
        return NULL;

    n = t->head;

    a = malloc(sizeof(int) * t->length);

    for (i = 0; i < t->length; i++) {
        a[i] = n->data;
        n = n->next;
    }
    
    return a;
}

char* adt_string(adt *t, char* iterable, size_t iter_len) {
    node *n;
    int len, i;
    char *s;
    
    if (!t->length)
        return NULL;

    len = t->length + (iter_len * t->length);
    s = malloc((sizeof(char)) * len);
    n = t->head;

    for (i = 0; i < len; i += iter_len + 1) {
        sprintf(&s[i], "%c", (char) n->data);

        if (i + iter_len + 1 < len)
            strcat(s, iterable);

        n = n->next;
    }

    return s;
}

void adt_clear(adt *t) {
    node *n;

    if (t->length) {
        n = t->head;

        while (t->head != NULL) {
            n = n->next;
            free(t->head);
            t->head = n;
        }

        t->head = NULL;
        t->tail = NULL;
        t->length = 0;
    }

    free(t);
}

int adt_empty(adt* t) {
    if (t->length)
        return 0;

    return 1;
}