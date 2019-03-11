#include <stdio.h>
#include "adt.h"

void* to_array(adt* t) {
    frame* f = t->head;

    if (!length(t))
        return NULL;

    int *a = malloc(sizeof(int) * length(t));

    for (int i = 0; i < length(t); i++) {
        a[i] = f->data;
        f = f->next;
    }
    
    return a;
}

char* to_string(adt* t, char* iterable) {
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

int peek(adt* t) {
    check_adt(t, "Can not peek empty structure");

    return t->head->data;
}

int length(adt* t) {
    if (t != NULL)
        return t->length;
    
    return -1;
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

void check_adt(adt* t, char* msg) {
    if (!length(t)) {
        printf("%s\n", msg);
        exit(1);
    }
}