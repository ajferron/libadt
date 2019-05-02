#include <stdio.h>
#include "adt.h"

void* to_array(adt* t) {
    node* n = t->head;

    if (!t->length)
        return NULL;

    int *a = malloc(sizeof(int) * t->length);

    for (int i = 0; i < t->length; i++) {
        a[i] = n->data;
        n = n->next;
    }
    
    return a;
}

char* to_string(adt* t, char* iterable) {
    if (!t->length)
        return NULL;

    node* n = t->head;
    int len = t->length + (strlen(iterable) * t->length);
    int i = 0;

    char *s = malloc((sizeof(char)) * len);
    
    while (1) {
        sprintf(&s[i], "%c", (char) n->data);
        
        if ((n = n->next) == NULL)
            break;

        strcat(s, iterable);
        i += strlen(iterable) + 1;
    }

    return s;

}

int peek(adt* t) {
    return t->head->data;
}

int length(adt* t) {
    if (t != NULL)
        return t->length;
    
    return -1;
}

void clear(adt* t) {
    if (t->length) {
        node* n = t->head;

        while (t->head != NULL) {
            n = n->next;
            free(t->head);
            t->head = n;
        }
    }

    t->tail = NULL;

    free(t);
    t = NULL;
}
