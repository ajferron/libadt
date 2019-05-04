#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "que.h"

#define TEST_STACK 1
#define TEST_QUE 1
#define TEST_LIST 1
#define N 10
#define C 'j'


int main(void) {
    list lst;
    stack stk;
    que q;
    int i, j;

    lst = init_list();
    stk = init_stack();
    q = init_que();


#if TEST_STACK

    int *s_arr;

    printf("\n-----------------------| TEST STACK |------------------------\n\n");

    for (i = 0; i < N; i++) 
        push(stk, i);

    s_arr = adt_array(stk) ;

    for (i = 0; i < N; i++)
        printf("%d ", s_arr[i]);

    printf("\n");

    for (i = 0; i < N; i++)
        printf("%d ", pop(stk));

    printf("\n");

    free(s_arr);

#endif


#if TEST_QUE

    int c, *q_arr;
    char *q_str;

    printf("\n------------------------| TEST QUE |-------------------------\n\n");

    for (c = 'a'; adt_length(q) < N; c++)
        enque(q, c);

    q_arr = adt_array(q);

    for (i = 0; i < N; i++)
        printf("%c ", q_arr[i]);

    q_str = adt_string(q, ", ");
    printf("\n%s\n", q_str);

    while (adt_length(q))
        printf("%c ", deque(q));

    printf("\n");

    free(q_arr);
    free(q_str);

#endif


#if TEST_LIST

    printf("\n------------------------| TEST LIST |------------------------\n");

    int *l_arr;

    for (i = 0; i < N; i++){
        printf("%c ", i);
        append(lst, i);
    }

    for (i = 0; i < N; i++) {
        set(lst, i, i + 50);
        printf("\nset(lst, %d, %d) \t get(%d) = %d \t adt_length(lst) = %d", i, i + 50, i, get(lst, i), adt_length(lst));
    }

    printf("\n");

    for (i = 0; i < N; i++)
        printf("\nfind(lst, %d) = %d", i + 50, find(lst, i + 50));

    printf("\n");

    for (i = 0; i < N*2; i+=2) {
        insert(lst, i, i + 1);
        printf("\ninsert(lst, %d, %d) \t get(%d + 1) = %d \t adt_length(lst) = %d\n", i, i + 1, i, get(lst, i + 1), adt_length(lst));

        l_arr = adt_array(lst);

        for (j = 0; j < adt_length(lst); j++)
            printf("%d ", l_arr[j]);

        printf("\n");

        free(l_arr);
    }

    while(adt_length(lst))
        printf("\ncut(lst, %d) = %d \t adt_length(lst) = %d", 0, cut(lst, 0), adt_length(lst));

    printf("\n\n");

#endif


    adt_clear(lst);
    adt_clear(stk);
    adt_clear(q);

    return 0;
}