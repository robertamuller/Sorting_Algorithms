# Sorting Algorithms

This repository contains implementations of two sorting algorithms along with their optimized versions, and a driver code showcasing tests for these functions.

## Algorithms Included:

1. **Bubble Sort**
   - Simple implementation of the bubble sort algorithm.
   
2. **Optimized Bubble Sort**
   - An optimized version of the bubble sort algorithm to reduce unnecessary comparisons and swaps.
   
3. **Selection Sort**
   - Implementation of the selection sort algorithm for sorting doubly linked list.
   
4. **Optimized Selection Sort**
   - A more efficient version of the selection sort algorithm with minimized number of swaps.

# Testing

## Test with a list with 12 elements

Using the following list
```bash
Payload: 84 87 78 16 94 36 87 93 50 22 63 28
```
We have the following results
```bash
Temp bubbleSort: 625 nanoseconds
Temp optimizedBubbleSort: 530 nanoseconds
Temp selectionSort: 620 nanoseconds
Temp optimizedSelectionSort: 562 nanoseconds
```
The sorted lists resulted to be:

```bash
Payload: 16 22 28 36 50 63 78 84 87 87 93 94
Payload: 16 22 28 36 50 63 78 84 87 87 93 94
Payload: 16 22 28 36 50 63 78 84 87 87 93 94
Payload: 16 22 28 36 50 63 78 84 87 87 93 94
```
## Test with a list with 10000 elements

Since the list is too big, we may just take a look of the first and last 5 elements

```bash
Head ... Tail: 8691 5060 7764 8927 541 ... 7230 6847 9903 13957 4753 
```
We have the following results
```bash
Temp bubbleSort:             233816844 nanoseconds
Temp optimizedBubbleSort:    217491761 nanoseconds
Temp selectionSort:          312120341 nanoseconds
Temp optimizedSelectionSort: 164788071 nanoseconds
```
Where the sorted head and tail becomes:
```bash
Head ... Tail: 1 2 3 4 9 ... 14980 14985 14985 14995 14997
Head ... Tail: 1 2 3 4 9 ... 14980 14985 14985 14995 14997
Head ... Tail: 1 2 3 4 9 ... 14980 14985 14985 14995 14997
Head ... Tail: 1 2 3 4 9 ... 14980 14985 14985 14995 14997
```
## Made by:

* [Gabriel Pavanato](https://github.com/Pavanato)
* [Roberta Muller Nunes](https://github.com/robertamuller)
