#include "adt.h"
#include "math.h"

set init_set(void) {
    set s;

    s = malloc(sizeof(adt));
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;

    return s;
}

void set_add(set s, int data) {
    node *n;

    n = malloc(sizeof(node));

    n->data = data;
    n->next = NULL;

    if (s->tail != NULL)
        s->tail->next = n;
        
    s->tail = n;
        
    if (s->head == NULL)
        s->head = s->tail;

    s->length++;
}

void remove_element(set s, int value) {
    node *n, *n1;

    if (!s->length)
        return;

    for (n = s->head; n->next != NULL; n = n->next)
        if (n->data == value) {
            if (s->length == 1) {
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

             s->length--;
        }
}

set set_union(set s1, set s2) {
    set s1_cpy, s2_cpy;
    node *n;

    s1_cpy = init_set();
    s2_cpy = init_set();

    for (n = s1->head; n != NULL; n = n->next)
        set_add(s1_cpy, n->data);

    for (n = s2->head; n != NULL; n = n->next)
        set_add(s2_cpy, n->data);

    if (s2 == NULL)
        return s1_cpy;

    else if (s1 == NULL)
        return s2_cpy;
    
    s1_cpy->tail->next = s2_cpy->head;

    return s1_cpy;
}

set set_intersection(set s1, set s2) {
    set s_new;
    node *n1, *n2;

    if (s1 == NULL || s2 == NULL)
        return init_set();
        
    s_new = init_set();

    for (n1 = s1->head; n1 != NULL; n1 = n1->next)
        for (n2 = s2->head; n2 != NULL; n2 = n2->next)
            if (n1->data == n2->data)
                set_add(s_new, n1->data);

    return s_new;
}

set interval(int a, int b) {
    set s;
    int i;

    s = init_set();

    for (i = a; i <= b; i++)
        set_add(s, i);

    return s;
}

int cardinality(set s) {
    return s->length;
}

int set_contains(set s, int value) {
    node *n;

    if (!s->length)
        return 0;

    n = s->head;

     for (n = s->head; n != NULL; n = n->next) 
        if (n->data == value)
            return 1;

    return 0;
}

int equivalent(set s1, set s2) {
    node *n1, *n2;
    
    if (s1->length != s2->length)
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

void free_set(set s) {
    node *n;

    if (s->length) {
        n = s->head;

        while (s->head != NULL) {
            n = n->next;
            free(s->head);
            s->head = n;
        }

        s->head = NULL;
        s->tail = NULL;
        s->length = 0;
    }

    free(s);
}