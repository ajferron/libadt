#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "multiset.h"

#define TEST_LIST 1
#define TEST_STACK 1
#define TEST_QUEUE 1
#define TEST_MSET 1
#define N 10
#define C 'j'


int main(void) {

    int i, j;

#if TEST_LIST

    list lst;
    int c, *l_arr;
    char *l_str;

    printf("\n------------------------| TEST LIST |------------------------\n\n");

    lst = create_list();
    c = 'a';

    for (i = 0; i < N; i++)
        list_append(lst, i + 10);

    for (i = 0; i < N; i++) {
        list_replace(lst, i, c + i);
        printf("\nlist_replace(lst, %d, %d) \t list_get(%d) = %d \t list_len(lst) = %d", i, c + i, i, list_get(lst, i), list_len(lst));
    }

    printf("\n\n");

    for (i = 0; i < N; i++)
        printf("\nlist_find(lst, %d) = %d", c + i, list_find(lst, c + i));

    printf("\n\n");

    for (i = 0; i < N*2; i += 2) {
        list_insert(lst, i, i + 2);
        printf("\nlist_insert(lst, %d, %d) | list_get(%d) = %d | list_len(lst) = %d\nlist = { ", i, i + 2, i, list_get(lst, i), list_len(lst));

        l_arr = list_array(lst);

        for (j = 0; j < list_len(lst); j++)
            printf("%d ", l_arr[j]);

        printf("}\n");

        free(l_arr);
    }

    printf("\n");
    
    for (i = 0, c = '0'; i < N*2; i += 2, c++) {
        list_replace(lst, i, c);
        printf("\nlist_replace(lst, %d, %d) | list_get(%d) = %d | list_len(lst) = %d\nlist = { ", i, c + i, i, list_get(lst, i), list_len(lst));

        l_arr = list_array(lst);

        for (j = 0; j < list_len(lst); j++)
            printf("%d ", l_arr[j]);

        printf("}\n");

        free(l_arr);
    }

    l_str = list_string(lst, ", ", 2);
    printf("\n\nlist_string(lst, \", \", 2) = \"%s\"\n\n", l_str);

    while(list_len(lst))
        printf("\nlist_cut(lst, %d) = %d \t list_len(lst) = %d", 0, list_cut(lst, 0), list_len(lst));

    printf("\n\n");

    free_list(lst);
    free(l_str);

#endif


#if TEST_STACK

    stack stk;

    printf("\n-----------------------| TEST STACK |------------------------\n\n");

    stk = create_stack();

    for (i = 0; i < N; i++) { 
        stack_push(stk, i);
        printf("stack_push(stk, %d) | stack_peek(stk) = %d\n", i, stack_peek(stk));
    }

    for (i = 0; i < N; i++)
        printf("\nstack_pop(stk) = %d", stack_pop(stk));

    printf("\n\n");

    free_stack(stk);

#endif


#if TEST_QUEUE

    queue q;

    printf("\n------------------------| TEST QUEUE |-------------------------\n\n");

    q = create_queue();

    for (i = 0; i < N; i++) { 
        enqueue(q, i);
        printf("enqueue(q, %d) | queue_head(q) = %d | queue_tail(q) = %d\n", i, queue_head(q), queue_tail(q));
    }


    while (!queue_empty(q))
        printf("\ndequeue(q) = %d", dequeue(q));

    printf("\n\n");

    free_queue(q);

#endif


#if TEST_MSET

    multiset ms1, ms2, ms_temp;

    printf("\n-------------------------| TEST SET |-------------------------\n");

    ms1 = create_mset();

    for (i = 0; i < N; i++)
        mset_add(ms1, i);

    printf("\ncardinality(ms1) = %d", cardinality(ms1));

    ms2 = interval(0, N);
    printf("\ncardinality(ms2) = %d\n", cardinality(ms2));

    for (i = 0; i <= N; i++)
        printf("\nmset_contains(ms1, %d) = %d", i, mset_contains(ms1, i));

    ms_temp = mset_union(ms1, ms2);
    printf("\n\ncardinality(mset_union(ms1, ms2)) = %d\n", cardinality(ms_temp));

    for (i = 0; i <= N; i++)
        printf("\nmultiplicity(msu, %d) = %d", i, multiplicity(ms_temp, i));

    free_mset(ms_temp);
    ms_temp = mset_intersection(ms1, ms2);
    printf("\n\ncardinality(mset_intersection(ms1, ms2)) = %d", cardinality(ms_temp));

    free_mset(ms_temp);
    ms_temp = mset_difference(ms2, ms1);
    printf("\n\ncardinality(mset_difference(ms2, ms1)) = %d", cardinality(ms_temp));

    printf("\n\nequivalent(ms2, ms1) = %d\n", equivalent(ms2, ms1));

    for (i = 0; i <= N; i++) {
        mset_remove(ms2, i);
        printf("\nmset_remove(ms2, %d) | mset_contains(ms2, %d) = %d | cardinality(ms2) = %d", i, i, mset_contains(ms2, i), cardinality(ms2));
    }

    printf("\n\n");

    free_mset(ms1);
    free_mset(ms2);
    free_mset(ms_temp);

#endif

    return 0;
}