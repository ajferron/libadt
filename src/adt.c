#include <string.h>
#include <stdio.h>
#include "adt.h"

void* toArray(adt* t) {
    frame* f = t->head;
    int len = t->length;
    int i;

    int32_t *a = malloc(sizeof(int32_t) * len);

    for (i = 0; i < len; i++) {
        a[i] = f->data;
        f = f->next;
    }
    
    return a;
}

char* toString(adt* t, char* iterable) {
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

int isEmpty(adt* t) {
    return (t->length == 0);
}

int length(adt* t) {
    return t->length;
}

void clear(adt* t) {
    frame* f = t->head;

    while (t->head != NULL) {
        f = f->next;
        free(t->head);
        t->head = f;
    }

    free(t->map);
    t->length = 0;
    t->tail = NULL;

    free(t);
    t = NULL;
}