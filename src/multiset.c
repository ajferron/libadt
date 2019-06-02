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

void mset_add(multiset s, void *data) {
    node *n;

    n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (s->tail != NULL)
        s->tail->next = n;
        
    s->tail = n;
        
    if (s->head == NULL)
        s->head = s->tail;

    s->cardinality++;
}

void mset_remove(multiset s, void *element) {
    node *n, *n1;

    if (!s->cardinality)
        return;

    for (n = s->head; n != NULL; n = n->next)
        if (n->data == element) {
            if (s->cardinality == 1) {
                s->head = NULL;
                free(n);

            } else if (n == s->head) {
                s->head = n->next;
                free(n);

            } else if (n == s->tail) {
                free(n->next);
                n->next = NULL;

            } else {
                n1 = (n->next)->next;
                free(n->next);
                n->next = n1;
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
    node *n1, *n2;

    if (!s1->cardinality || !s2->cardinality)
        return create_mset();
        
    s_new = create_mset();

    for (n1 = s1->head; n1 != NULL; n1 = n1->next)
        for (n2 = s2->head; n2 != NULL; n2 = n2->next)
            if (n1->data == n2->data)
                mset_add(s_new, n1->data);

    return s_new;
}

multiset mset_difference(multiset s1, multiset s2) {
    multiset s_new;
    node *n1, *n2;

    if (!s1->cardinality)
        return create_mset();

    if (!s2->cardinality)
        return mset_copy(s1);

    s_new = create_mset();

    for (n1 = s1->head; n1 != NULL; n1 = n1->next) {
        for (n2 = s2->head; n2 != NULL; n2 = n2->next)
            if (n1->data == n2->data)
                break;

        if (n2 == NULL)
            mset_add(s_new, n1->data);
    }

    return s_new;
}

int mset_contains(multiset s, void *element) {
    node *n;

    if (!s->cardinality)
        return 0;

    n = s->head;

     for (n = s->head; n != NULL; n = n->next) 
        if (n->data == element)
            return 1;

    return 0;
}

multiset mset_copy(multiset s) {
    multiset s_cpy;
    node *n;

    s_cpy = create_mset();

    for (n = s->head; n != NULL; n = n->next)
        mset_add(s_cpy, n->data);

    return s_cpy;
}

int multiplicity(multiset s, void *element) {
    node *n;
    int m;

    n = s->head;
    m = 0;

    for (n = s->head; n != NULL; n = n->next)
        if (n->data == element)
            m++;

    return m;
}

int cardinality(multiset s) {
    return s->cardinality;
}

int equivalent(multiset s1, multiset s2) {
    node *n1, *n2;
    
    if (s1->cardinality != s2->cardinality)
        return 0;

    for (n1 = s1->head; n1 != NULL; n1 = n1->next) {
        for (n2 = s2->head; n2 != NULL; n2 = n2->next)
            if (n1->data == n2->data)
                break;

        if (n2 == NULL)
            return 0;
    }

    return 1;
}

void free_mset(multiset s) {
    node *n;

    if (s->cardinality) {
        n = s->head;

        while (s->head != NULL) {
            n = n->next;
            free(s->head);
            s->head = n;
        }

        s->head = NULL;
        s->tail = NULL;
        s->cardinality = 0;
    }

    free(s);
}