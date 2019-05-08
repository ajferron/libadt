#include <stdlib.h>
#include <stdio.h>
#include "multiset.h"

multiset create_mset(void) {
    multiset s;

    s = malloc(sizeof(multiset));
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;

    return s;
}

void mset_add(multiset s, int data) {
    element *e;

    e = malloc(sizeof(element));

    e->data = data;
    e->next = NULL;

    if (s->tail != NULL)
        s->tail->next = e;
        
    s->tail = e;
        
    if (s->head == NULL)
        s->head = s->tail;

    s->length++;
}

void remove_element(multiset s, int value) {
    element *e, *e1;

    if (!s->length)
        return;

    for (e = s->head; e->next != NULL; e = e->next)
        if (e->data == value) {
            if (s->length == 1) {
                s->head = NULL;
                free(e);

            } else if (e == s->head) {
                s->head = e->next;
                free(e);

            } else if (e == s->tail) {
                free(e->next);
                e->next = NULL;

            } else {
                e1 = (e->next)->next;
                free(e->next);
                e->next = e1;
            }

             s->length--;
        }
}

multiset mset_union(multiset s1, multiset s2) {
    multiset s1_cpy, s2_cpy;
    element *e;

    s1_cpy = create_mset();
    s2_cpy = create_mset();

    for (e = s1->head; e != NULL; e = e->next)
        mset_add(s1_cpy, e->data);

    for (e = s2->head; e != NULL; e = e->next)
        mset_add(s2_cpy, e->data);

    if (s2 == NULL)
        return s1_cpy;

    else if (s1 == NULL)
        return s2_cpy;
    
    s1_cpy->tail->next = s2_cpy->head;

    return s1_cpy;
}

multiset mset_intersection(multiset s1, multiset s2) {
    multiset s_new;
    element *e1, *e2;

    if (s1 == NULL || s2 == NULL)
        return create_mset();
        
    s_new = create_mset();

    for (e1 = s1->head; e1 != NULL; e1 = e1->next)
        for (e2 = s2->head; e2 != NULL; e2 = e2->next)
            if (e1->data == e2->data)
                mset_add(s_new, e1->data);

    return s_new;
}

multiset interval(int a, int b) {
    multiset s;
    int i;

    s = create_mset();

    for (i = a; i <= b; i++)
        mset_add(s, i);

    return s;
}

int cardinality(multiset s) {
    return s->length;
}

int mset_contains(multiset s, int value) {
    element *e;

    if (!s->length)
        return 0;

    e = s->head;

     for (e = s->head; e != NULL; e = e->next) 
        if (e->data == value)
            return 1;

    return 0;
}

int equivalent(multiset s1, multiset s2) {
    element *e1, *e2;
    
    if (s1->length != s2->length)
        return 0;

    for (e1 = s1->head; e1 != NULL; e1 = e1->next) {
        for (e2 = s2->head; e2 != NULL; e2 = e2->next)
            if (e1->data == e2->data)
                break;

        if (e2 == NULL)
            return 0;
    }

    return 1;
}

void free_mset(multiset s) {
    element *e;

    if (s->length) {
        e = s->head;

        while (s->head != NULL) {
            e = e->next;
            free(s->head);
            s->head = e;
        }

        s->head = NULL;
        s->tail = NULL;
        s->length = 0;
    }

    free(s);
}