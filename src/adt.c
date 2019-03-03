#include <stdio.h>
#include "adt.h"

void* toArray(adt* t) {
    frame* f = t->head;

    if (!length(t))
        return NULL;

    int32_t *a = malloc(sizeof(int32_t) * length(t));

    for (int i = 0; i < length(t); i++) {
        a[i] = f->data;
        f = f->next;
    }
    
    return a;
}

char* toString(adt* t, char* iterable) {
    if (!length(t))
        return NULL;

    frame* f = t->head;
    int len = t->length + (strlen(iterable) * t->length);
    int i = 0;

    char *s = malloc((sizeof(char)) * len);
    
    while (1) {
        sprintf(&s[i], "%c", (char) f->data);
        
        if ((f = f->next) == NULL)
            break;

        strcat(s, iterable);
        i += strlen(iterable) + 1;
    }

    return s;

}

int32_t peek(adt* t) {
    return (t->head->data);
}

int length(adt* t) {
    return t->length;
}

void clear(adt* t) {
    if (length(t)) {
        frame* f = t->head;

        while (t->head != NULL) {
            f = f->next;
            free(t->head);
            t->head = f;
        }
    }

    t->tail = NULL;

    free(t);
    t = NULL;
}