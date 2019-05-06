#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"

#define TEST_LIST 1
#define TEST_STACK 1
#define TEST_QUEUE 1
#define TEST_SET 1
#define N 10
#define C 'j'


int main(void) {
    list lst;
    stack stk;
    queue q;
    int i, j;

    lst = init_list();
    stk = init_stack();
    q = init_queue();


#if TEST_STACK

    int *s_arr;

    printf("\n-----------------------| TEST STACK |------------------------\n\n");

    for (i = 0; i < N; i++) 
        stack_push(stk, i);

    s_arr = adt_array(stk) ;

    for (i = 0; i < N; i++)
        printf("%d ", s_arr[i]);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%d ", stack_pop(stk));

    printf("\n");

    free(s_arr);

#endif


#if TEST_QUEUE

    int c, *q_arr;
    char *q_str;

    printf("\n------------------------| TEST QUEUE |-------------------------\n\n");

    for (c = 'a'; c < C; c++)
        enqueue(q, c);

    q_arr = adt_array(q);

    for (i = 0; i < N; i++)
        printf("%c ", q_arr[i]);

    q_str = adt_string(q, ", ", 2);
    printf("\n%s\n", q_str);

    while (!adt_empty(q))
        printf("%c ", dequeue(q));

    printf("\n");

    free(q_arr);
    free(q_str);

#endif


#if TEST_LIST

    printf("\n------------------------| TEST LIST |------------------------\n");

    int *l_arr;

    for (i = 0; i < N; i++){
        printf("%c ", i);
        list_append(lst, i);
    }

    for (i = 0; i < N; i++) {
        list_replace(lst, i, i + 50);
        printf("\nlist_replace(lst, %d, %d) \t list_get(%d) = %d \t list_len(lst) = %d", i, i + 50, i, list_get(lst, i), list_len(lst));
    }

    printf("\n");

    for (i = 0; i < N; i++)
        printf("\nlist_find(lst, %d) = %d", i + 50, list_find(lst, i + 50));

    printf("\n");

    for (i = 0; i < N*2; i+=2) {
        list_insert(lst, i, i + 1);
        printf("\nlist_insert(lst, %d, %d) \t list_get(%d + 1) = %d \t list_lstlen(lst) = %d\n", i, i + 1, i, list_get(lst, i + 1), list_len(lst));

        l_arr = adt_array(lst);

        for (j = 0; j < list_len(lst); j++)
            printf("%d ", l_arr[j]);

        printf("\n");

        free(l_arr);
    }

    while(list_len(lst))
        printf("\nlist_cut(lst, %d) = %d \t list_len(lst) = %d", 0, list_cut(lst, 0), list_len(lst));

    printf("\n\n");

#endif


    adt_clear(lst);
    adt_clear(stk);
    adt_clear(q);

    return 0;
}