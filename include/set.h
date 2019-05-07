#ifndef _SET_H_
#define _SET_H_

#define EMPTY_SET NULL

struct element {
    int data;
    struct element *next;
};

typedef struct element element;

struct set {
    element *head;
    element *tail;
    int length;
};

typedef struct set *set;


/* Initialize the set data structure */
set init_set(void);

/* Add an integer to set */
void set_add(set, int data);

/* Remove an integer from the set */
void remove_element(set, int);

/* Returns a set of all integers contained by s1 or s2 */
set set_union(set s1, set s2);

/* Returns the set of all integers that are elements of s1 and s2 */
set set_intersection(set s1, set s2);

/* Returns the set of all the integers greater than or equal to a and less than or equal to b */
set interval(int a, int b);

/* Return the number of distinct elements in a set */
int cardinality(set);

/* Return 0 if the set does not contain the value and 1 otherwise*/
int set_contains(set, int);

/* Return 0 if there exists an element that is contained by one set and not the other and 1 otherwise */
int equivalent(set s1, set s2);

/* Free all memory allocated to the data structure */
void free_set(set);

#endif