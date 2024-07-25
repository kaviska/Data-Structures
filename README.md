# Data Structures and Algorithms in C

This repository contains implementations of various data structures and algorithms using the C programming language.

## Table of Contents

- [Singly Linked List](#singly-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [Queue](#queue)
- [Stack](#stack)
- [Sorting Algorithms](#sorting-algorithms)

## Singly Linked List

A singly linked list is a data structure that consists of a sequence of elements, each containing a reference (or link) to the next element in the sequence. This section includes implementations of all standard operations on singly linked lists, including:

- Insert at the beginning
- Insert at the end
- Insert at a specific position
- Delete from the beginning
- Delete from the end
- Delete at a specific position
- Search data
- Update data
- Display
- Free Linked List

### Files

- `singlyLinkList.c`

## Doubly Linked List

A doubly linked list is similar to a singly linked list, but each element contains two references: one to the next element and one to the previous element. This section includes implementations of all standard operations on doubly linked lists, including:

- Insert at the beginning
- Insert at the end
- Insert at a specific position
- Print the list forward
- Print the list backward
- Find maximum and minimum
- Print the list as circular

### Files

- `doublyLinkList.c`

## Queue

A queue is a linear data structure that follows the First In First Out (FIFO) principle. This section includes implementations of queues using both linked lists and arrays, covering operations such as:

- Enqueue
- Dequeue
- Peek
- IsEmpty
- IsFull (for array implementation)

### Files

- `queue_linked_list.c`
- `queue_linked_list.h`
- `queue_array.c`
- `queue_array.h`

## Stack

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. This section includes implementations of stacks using both linked lists and arrays, covering operations such as:

- Push
- Pop
- Peek
- IsEmpty
- IsFull (for array implementation)

### Files

- `stack_linked_list.c`
- `stack_linked_list.h`
- `stack_array.c`
- `stack_array.h`

## Sorting Algorithms

This section includes implementations of three common sorting algorithms:

### Selection Sort

Selection sort is an in-place comparison sorting algorithm. It divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list.

### Files

- `selection_sort.c`
- `selection_sort.h`

### Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

### Files

- `bubble_sort.c`
- `bubble_sort.h`

### Insertion Sort

Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

### Files

- `insertion_sort.c`
- `insertion_sort.h`

## Getting Started

To compile any of the implementations, you can use the following command:

```sh
gcc -o output_file source_file.c
```
