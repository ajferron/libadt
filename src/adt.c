#include <stdio.h>
#include "adt.h"

void* adt_array(adt* t) {
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

char* adt_string(adt* t, char* iterable) {
    node *n;
    int len, i;
    char *s;
    
    if (!t->length)
        return NULL;

    n = t->head;
    len = t->length + (strlen(iterable) * t->length);
    i = 0;

    s = malloc((sizeof(char)) * len);

    for (i = 0; (n = n->next) != NULL; i += strlen(iterable) + 1) {
        sprintf(&s[i], "%c", (char) n->data);
        strcat(s, iterable);
    }

    return s;

}

int adt_peek(adt* t) {
    return t->head->data;
}

int adt_length(adt* t) {
    if (t != NULL)
        return t->length;
    
    return -1;
}

void adt_clear(adt* t) {
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
    t = NULL;
}
