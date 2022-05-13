# Fun With Linked Lists
## Description

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. k is a positive integer
and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then
left-out nodes, in the end, should remain as it is. You may not alter the values in the list’s nodes, only nodes
themselves may be changed. Figures 1 and 2 show the list before and after swapping each disjoint k size
sublists to get a better idea.

![](https://user-images.githubusercontent.com/98181344/168372519-5021200e-ec21-4ca7-8708-f85d75aaaa68.png)  |  ![](https://user-images.githubusercontent.com/98181344/168373276-2fa02284-3252-4254-8df5-3da85d203d42.png)
:-------------------------:|:-------------------------:
Figure 1: Before and after, list size 5 and k = 2             |  Figure 2: Before and after, list size 5 and k = 3

## Contents of main

In main you prompt for a list size which we will call n. You then create an object of type `LL<int>` and add
integers 1 to n into this list, then prompt for the k value. You then output the original list then output the
list after having each disjoint size k sub-list reversed. You should re-prompt if the user does not enter a non
negative number for n and k.

## Specifications

- Comment your code and functions
- When reversing the sub-lists, you need to rearrange the nodes, you cannot just simply swap the data
    fields of existing nodes (this makes the code for reversing the linked list harder but more efficient in
    the general case), you also cannot reconstruct each sub-list by deallocating and reallocating nodes
- Your code cannot have memory leaks

## Sample Run

```
$ g++ fwll.cpp
$ ./a.out
```
```
Enter n and k: hi bye
Enter n and k: 7 0
Enter n and k: -8 0
Enter n and k: 10 2

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 8 -> 7 -> 10 -> 9
```
```
$ ./a.out

Enter n and k: 10 3

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> 10
```
```
$ ./a.out

Enter n and k: 10 10

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
10 -> 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1
```
```
$ ./a.out

Enter n and k: 10 5

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
5 -> 4 -> 3 -> 2 -> 1 -> 10 -> 9 -> 8 -> 7 -> 6
```
```
$ ./a.out

Enter n and k: 10 1

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
```
```
$ ./a.out

Enter n and k: 10 4

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5 -> 9 -> 10
```
```
$ ./a.out

Enter n and k: 10 8

Original List
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10

Reversed list
8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 9 -> 10
```
