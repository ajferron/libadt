#include <stdlib.h>
#include <stdio.h>
#include "multiset.h"

multiset create_mset(void) {
    multiset s;

    s = malloc(sizeof(struct multiset));
    s->head = NULL;
    s->tail = NULL;
    s->cardinality = 0;

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

    s->cardinality++;
}

void mset_remove(multiset s, int value) {
    element *e, *e1;

    if (!s->cardinality)
        return;

    for (e = s->head; e->next != NULL; e = e->next)
        if (e->data == value) {
            if (s->cardinality == 1) {
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

             s->cardinality--;
        }
}

multiset mset_union(multiset s1, multiset s2) {
    multiset s1_cpy, s2_cpy;

    s1_cpy = mset_copy(s1);
    s2_cpy = mset_copy(s2);

    if (s2 == NULL)
        return s1_cpy;

    else if (s1 == NULL)
        return s2_cpy;
    
    s1_cpy->tail->next = s2_cpy->head;
    s1_cpy->cardinality += s2->cardinality;

    return s1_cpy;
}

multiset mset_intersection(multiset s1, multiset s2) {
    multiset s_new;
    element *e1, *e2;

    if (!s1->cardinality || !s2->cardinality)
        return create_mset();
        
    s_new = create_mset();

    for (e1 = s1->head; e1 != NULL; e1 = e1->next)
        for (e2 = s2->head; e2 != NULL; e2 = e2->next)
            if (e1->data == e2->data)
                mset_add(s_new, e1->data);

    return s_new;
}

multiset mset_difference(multiset s1, multiset s2) {
    multiset s_new;
    element *e1, *e2;

    if (!s1->cardinality)
        return create_mset();

    if (!s2->cardinality)
        return mset_copy(s1);

    s_new = create_mset();

    for (e1 = s1->head; e1 != NULL; e1 = e1->next) {
        for (e2 = s2->head; e2 != NULL; e2 = e2->next)
            if (e1->data == e2->data)
                break;

        if (e2 == NULL)
            mset_add(s_new, e1->data);
    }

    return s_new;
}

int mset_contains(multiset s, int value) {
    element *e;

    if (!s->cardinality)
        return 0;

    e = s->head;

     for (e = s->head; e != NULL; e = e->next) 
        if (e->data == value)
            return 1;

    return 0;
}

multiset mset_copy(multiset s) {
    multiset s_cpy;
    element *e;

    s_cpy = create_mset();

    for (e = s->head; e != NULL; e = e->next)
        mset_add(s_cpy, e->data);

    return s_cpy;
}

multiset interval(int a, int b) {
    multiset s;
    int i;

    s = create_mset();

    for (i = a; i <= b; i++)
        mset_add(s, i);

    return s;
}

int multiplicity(multiset s, int value) {
    element *e;
    int m;

    e = s->head;
    m = 0;

    for (e = s->head; e != NULL; e = e->next)
        if (e->data == value)
            m++;

    return m;
}

int cardinality(multiset s) {
    return s->cardinality;
}

int equivalent(multiset s1, multiset s2) {
    element *e1, *e2;
    
    if (s1->cardinality != s2->cardinality)
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

    if (s->cardinality) {
        e = s->head;

        while (s->head != NULL) {
            e = e->next;
            free(s->head);
            s->head = e;
        }

        s->head = NULL;
        s->tail = NULL;
        s->cardinality = 0;
    }

    free(s);
}