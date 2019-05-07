#include <stdlib.h>
#include <stdio.h>
#include "set.h"
#include "math.h"

set create_set(void) {
    set s;

    s = malloc(sizeof(set));
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;

    return s;
}

void set_add(set s, int data) {
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

void remove_element(set s, int value) {
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

set set_union(set s1, set s2) {
    set s1_cpy, s2_cpy;
    element *e;

    s1_cpy = create_set();
    s2_cpy = create_set();

    for (e = s1->head; e != NULL; e = e->next)
        set_add(s1_cpy, e->data);

    for (e = s2->head; e != NULL; e = e->next)
        set_add(s2_cpy, e->data);

    if (s2 == NULL)
        return s1_cpy;

    else if (s1 == NULL)
        return s2_cpy;
    
    s1_cpy->tail->next = s2_cpy->head;

    return s1_cpy;
}

set set_intersection(set s1, set s2) {
    set s_new;
    element *e1, *e2;

    if (s1 == NULL || s2 == NULL)
        return create_set();
        
    s_new = create_set();

    for (e1 = s1->head; e1 != NULL; e1 = e1->next)
        for (e2 = s2->head; e2 != NULL; e2 = e2->next)
            if (e1->data == e2->data)
                set_add(s_new, e1->data);

    return s_new;
}

set interval(int a, int b) {
    set s;
    int i;

    s = create_set();

    for (i = a; i <= b; i++)
        set_add(s, i);

    return s;
}

int cardinality(set s) {
    return s->length;
}

int set_contains(set s, int value) {
    element *e;

    if (!s->length)
        return 0;

    e = s->head;

     for (e = s->head; e != NULL; e = e->next) 
        if (e->data == value)
            return 1;

    return 0;
}

int equivalent(set s1, set s2) {
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

void free_set(set s) {
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