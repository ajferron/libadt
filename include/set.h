#ifndef _SET_H_
#define _SET_H_

#include "adt.h"

/* Initialize the set data structure */
set init_set(void);

/* Add an integer to set if it is not already contained */
void add(set, int data);

/* Remove an integer from the set */
void remove(set, int);

/* Returns a set of all integers contained by s1 or s2 (i.e. the union of 2 sets) */
set unite(set s1, set s2);

/* Returns the set of all integers that are elements of s1 and s2 (i.e. the intersection of 2 sets) */
set intersect(set s1, set s2);

/* Returns the set of all integers that are elements of s1 and not elements of s2 and not elements of both */
set difference(set s1, set s2);

/* Returns the set of all integers that are elements of s1 or elements of s2 but not both */
set symmetric_difference(set s1, set s2);

/* Returns the set of all the integers greater than or equal to n and less than or equal to m */
set interval(int n, int m);

/* Returns a pointer to all the subsets of a set */
set* power_set(set);

/* Return the number of distinct elements in a set */
int cardinality(set);

/* Return 0 if the set does not contain the value and 1 otherwise*/
int contains(set, int);

/* Return 0 if there exists an element that is contained by one set and not the other and 1 otherwise */
int equals(set s1, set s2);

#endif