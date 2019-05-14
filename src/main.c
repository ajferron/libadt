#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "multiset.h"

#define TEST_LIST 1
#define TEST_STACK 1
#define TEST_QUEUE 1
#define TEST_SET 0
#define N 10
#define C 'j'


int main(void) {
    list lst;
    stack stk;
    queue q;

    int i, j;

#if TEST_LIST

    int c, *l_arr;
    char *l_str;

    lst = create_list();
    c = 'a';

    printf("\n------------------------| TEST LIST |------------------------\n\n");

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

    stk = create_stack();

    printf("\n-----------------------| TEST STACK |------------------------\n");

    for (i = 0; i < N; i++) { 
        stack_push(stk, i);
        printf("\nstack_push(stk, %d) | stack_peek(stk) = %d ", i, stack_peek(stk));
    }

    printf("\n\n");

    for (i = 0; i < N; i++)
        printf("\nstack_pop(stk) = %d", stack_pop(stk));

    printf("\n\n");

    free_stack(stk);

#endif


#if TEST_QUEUE

    q = create_queue();

    printf("\n------------------------| TEST QUEUE |-------------------------\n");

    for (i = 0; i < N; i++) { 
        enqueue(q, i);
        printf("\nenqueue(q, %d) | queue_head(q) = %d | queue_tail(q) = %d", i, queue_head(q), queue_tail(q));
    }

    printf("\n\n");

    while (!queue_empty(q))
        printf("\ndequeue(q) = %d", dequeue(q));

    printf("\n\n");

    free_queue(q);

#endif

    return 0;
}