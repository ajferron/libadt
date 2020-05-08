# libadt 
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/127d5c30fa534f46beec2516c5ce579b)](https://www.codacy.com/app/af3r/libadt?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=af3r/libadt&amp;utm_campaign=Badge_Grade)

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/f710818856424856a53ea09b2d25f142)](https://app.codacy.com/app/af3r/libadt?utm_source=github.com&utm_medium=referral&utm_content=af3r/libadt&utm_campaign=Badge_Grade_Dashboard)

## Structures

### List
> In computer science, a list or sequence is an abstract data type that represents a countable number of ordered values, where the same value may occur more than once. - [Wikipedia](https://en.wikipedia.org/wiki/List_(abstract_data_type))

#### Implementation

| Function Name | Complexity | Description                                                                     |
| :------------ | :--------: | :-------------------------------------------------------------------------------| 
| create_list   | O(1)       | Initialize list data structure                                                  |
| list_prepend  | O(1)       | Add an element to the front of the list                                         |
| list_append   | O(1)       | Add an element to the end of the list                                           |
| list_insert   | O(n)       | Insert an element after the given index                                         |
| list_get      | O(n)       | Return the element at an index                                                  |
| list_find     | O(n)       | Return the index of the first occurrence of an item or -1 if unfound            |
| list_replace  | O(n)       | Replace an element at an index                                                  |
| list_cut      | O(n)       | Remove the element at an index and return it's data                             |
| list_len      | O(1)       | Return the number of elements in the list if it is initialized and -1 otherwise |
| free_list     | O(n)       | Free all memory allocated to the data structure                                 |

___

### Stack
> In computer science, a stack is an abstract data type that serves as a collection of elements. The order in which elements come off a stack gives rise to its alternative name, LIFO (last in, first out). - [Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

#### Implementation

| Function Name | Complexity | Description                                           |
| :------------ | :--------: | :-----------------------------------------------------| 
| create_stack  | O(1)       | Initialize stack data structure                       |
| stack_push    | O(1)       | Add an element to the top of stack                    |
| stack_pop     | O(1)       | Remove and return the element at the top of the stack |
| stack_peek    | O(1)       | Return the element at the top of the stack            |
| stack_empty   | O(1)       | Return 1 if the queue is empty and 0 otherwise        |
| free_stack    | O(n)       | Free all memory allocated to the data structure       |

___

### Queue

> In computer science, a queue is a collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. - [Wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

#### Implementation

| Function Name | Complexity | Description                                             |
| :------------ | :--------: | :-------------------------------------------------------|
| create_queue  | O(1)       | Initialize queue data structure                         |
| enqueue       | O(1)       | Add an element to the end of queue                      |
| dequeue       | O(1)       | Remove and return the element at the front of the queue |
| queue_head    | O(1)       | Return the element at the front of the queue            |
| queue_tail    | O(1)       | Return the element at the end of the queue              |
| queue_empty   | O(1)       | Return 1 if the queue is empty and 0 otherwise          |
| free_queue    | O(n)       | Free all memory allocated to the data structure         |

___

### Multiset

> In mathematics, a multiset (aka bag or mset) is a modification of the concept of a [set](https://en.wikipedia.org/wiki/Set_(abstract_data_type)) that, unlike a set, allows for multiple instances for each of its elements. The positive integer number of instances, given for each element is called the multiplicity of this element in the multiset. - [Wikipedia](https://en.wikipedia.org/wiki/Multiset)

#### Implementation

| Function Name     | Complexity | Description                                                                   |
| :---------------- | :--------: | :---------------------------------------------------------------------------- |
| create_mset       | O(1)       | Initialize multiset data structure                                            |
| mset_add          | O(1)       | Add an element to the multiset                                                |
| remove_element    | O(1)       | Remove all occurences of an element from the multiset                         |
| mset_union        | O(1)       | Returns a multiset that contains all elements of 2 multisets                  |
| mset_intersection | O(1)       | Returns a multiset of all elements that are common between 2 multisets        |
| mset_difference   | O(1)       | Returns the difference of two multisets                                       |
| multiplicity      | O(n)       | Returns the number of occurences of an element                                |
| cardinality       | O(n)       | Return the number of distinct elements                                        |
| mset_contains     | O(n)       | Return 1 if the set contains the element and 0 otherwise                      |
| equivalent        | O(n)       | Return 1 if 2 sets contain the same elements, each with the same multiplicity |
| free_mset         | O(n)       | Free all memory allocated to the data structure                               |
