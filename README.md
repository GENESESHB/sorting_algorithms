# sorting_algorithms
@project_bigO&amp;AlgoSort


# Bubble sort

`
explining all thing about my code
`

```c
#include "sort.h"
```
This line includes the header file "sort.h". The header file likely contains function prototypes and any necessary definitions for the sorting functions used in this program.

```c
/**
 *swap - a function that swaps two integers.
 *@a: first integer to swap.
 *@b: second integer to swap.
 *
 * Return: void.
 */
```
This is a function comment block, documenting the `swap` function. It explains what the function does and provides information about its parameters and return value. The `swap` function is intended to swap the values of two integers and takes two integer pointers (`a` and `b`) as parameters. It does not return anything (`void`).

```c
void swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}
```
This is the implementation of the `swap` function. It uses a temporary variable `x` to swap the values of the integers pointed to by `a` and `b`. After the swapping, `a` will point to the value that was originally stored in `b`, and `b` will point to the value that was originally stored in `a`.

```c
/**
 *bubble_sort - a function that sorts an array using
 *using bubble sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */
```
Similar to before, this is a function comment block for the `bubble_sort` function. It provides information about what the function does and describes its parameters and return value. The `bubble_sort` function is intended to sort an integer array (`array`) using the Bubble Sort algorithm. The parameter `size` specifies the size of the array. The function does not return anything (`void`).

```c
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    if (array == NULL || size == 0)
        return;
```
The `bubble_sort` function begins with the declaration of two variables, `i` and `j`, both of type `size_t`, which are used for loop indices.

Next, the function checks if the `array` is `NULL` or if its size is 0. If either of these conditions is true, the function immediately returns without performing any sorting, as there is nothing to sort.

```c
    for (i = size - 1; i > 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (array[j - 1] > array[j])
            {
                swap(&array[j - 1], &array[j]);
                print_array(array, size);
            }
        }
    }
}
```
The nested loops here implement the Bubble Sort algorithm.

The outer loop runs from `size - 1` down to 1. It represents the number of passes the algorithm will make over the array.

The inner loop runs from 1 to `i`. It represents the comparison and swapping phase of Bubble Sort within each pass. As mentioned before, the inner loop starts from 1 because the largest element in each pass will "bubble up" to its correct position, so we don't need to check the last element after each iteration of the outer loop.

Within the inner loop, the function compares the element at index `j - 1` with the element at index `j`. If the element at `j - 1` is greater than the element at `j`, it means they are out of order. In that case, the `swap` function is called to swap the elements, effectively "bubbling up" the larger element.

After each swap, the `print_array` function (not shown in this code snippet) is called to print the current state of the array. This can be useful to visualize the sorting process.

The Bubble Sort algorithm will continue until the array is completely sorted, and the largest element has "bubbled up" to its correct position.



# Insertion sort

`
explining all thing about my code
`

```c
#include "sort.h"
```
This line includes the header file "sort.h". The header file likely contains necessary function prototypes and definitions for the functions used in this program.

```c
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: pointer to the head of the doubly-linked list.
 * @node1: pointer to the first node to swap.
 * @node2: second node to swap.
 */
```
This is a function comment block, documenting the `swap_nodes` function. It explains what the function does and provides information about its parameters. The `swap_nodes` function is intended to swap two nodes in a doubly-linked list (`listint_t`). The parameters are:

- `head`: A pointer to the head of the doubly-linked list.
- `node1`: A pointer to the first node to be swapped.
- `node2`: A pointer to the second node to be swapped.

```c
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
        (*node1)->next = node2->next;
        if (node2->next != NULL)
                node2->next->prev = *node1;
        node2->prev = (*node1)->prev;
        node2->next = *node1;
        if ((*node1)->prev != NULL)
                (*node1)->prev->next = node2;
        else
                *head = node2;
        (*node1)->prev = node2;
        (*node1) = node2->prev;
}
```
This is the implementation of the `swap_nodes` function. It swaps two nodes (`node1` and `node2`) in a doubly-linked list.

The function begins by updating the `next` pointer of `node1` to point to the node that comes after `node2`. Similarly, it updates the `prev` pointer of `node2` to point to the node that comes before `node1`.

Next, it adjusts the pointers of the neighboring nodes to reflect the new connections after the swap. If `node1` had a node before it, then that node's `next` pointer is updated to point to `node2`. Otherwise, if `node1` was the head of the list, `*head` is updated to point to `node2` since `node2` is now the new head.

Finally, the function updates the `prev` pointer of `node1` to point to the node that comes before `node2`. This step is necessary to maintain the integrity of the doubly-linked list.

```c
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in order
 * @list: A pointer of  head  the doubly linked list.
 *
 */
```
This is a function comment block for the `insertion_sort_list` function. It provides information about what the function does and describes its parameter. The `insertion_sort_list` function is intended to sort a doubly-linked list of integers in ascending order. The parameter `list` is a pointer to the head of the doubly-linked list.

```c
void insertion_sort_list(listint_t **list)
{
        listint_t *cle, *insert, *tp;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        for (cle = (*list)->next; cle != NULL; cle = tp)
        {
                tp = cle->next;
                insert = cle->prev;
                while (insert != NULL && cle->n < insert->n)
                {
                        swap_nodes(list, &insert, cle);
                        print_list((const listint_t *)*list);
                }

        }
}
```
This is the implementation of the `insertion_sort_list` function. It sorts the doubly-linked list in ascending order using the Insertion Sort algorithm.

The function first checks if the `list` is `NULL`, if the list is empty (`*list == NULL`), or if there's only one element in the list (`(*list)->next == NULL`). If any of these conditions is true, it means the list is either empty or already sorted, so the function simply returns without performing any sorting.

The function then proceeds with the insertion sort algorithm. It uses three pointers, `cle`, `insert`, and `tp`, where `cle` points to the current node, `insert` points to the node before `cle`, and `tp` is used to keep track of the next node to be processed during the sorting process.

The outer loop (for-loop) runs through the list, starting from the second node (`(*list)->next`) until the end of the list (`cle != NULL`). This loop goes through each node and tries to insert the current node (`cle`) into its correct position in the sorted portion of the list.

The inner loop (while-loop) compares the value of the current node (`cle->n`) with the value of the node before it (`insert->n`). It continues swapping the nodes using the `swap_nodes` function until the current node (`cle`) is in its correct position (i.e., it's greater than or equal to the node before it). After each swap, the `print_list` function (not shown in this code snippet) is called to print the current state of the list. This can be useful to visualize the sorting process.

The insertion sort algorithm continues until all nodes are in their correct positions, resulting in a sorted doubly-linked list

# Selection sort

Sure, let's go through this code line by line:

```c
#include "sort.h"
```
This line includes the header file "sort.h". The header file likely contains necessary function prototypes and definitions for the functions used in this program.

```c
/**
 *swap - Swap two integers in an array.
 *@a: The first integer to swap.
 *@b: The second integer to swap.
 */
```
This is a function comment block, documenting the `swap` function. It explains what the function does and provides information about its parameters. The `swap` function is intended to swap two integers in an array. The parameters are:

- `a`: A pointer to the first integer to be swapped.
- `b`: A pointer to the second integer to be swapped.

```c
void swap(int *a, int *b)
{
        int x;

        x = *a;
        *a = *b;
        *b = x;
}
```
This is the implementation of the `swap` function. It swaps the values of two integers pointed to by `a` and `b` using a temporary variable `x`. After the swapping, `a` will point to the value that was originally stored in `b`, and `b` will point to the value that was originally stored in `a`.

```c
/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: prints the array after each swap.
 */
```
This is a function comment block for the `selection_sort` function. It provides information about what the function does and describes its parameters. The `selection_sort` function is intended to sort an array of integers in ascending order using the Selection Sort algorithm. The parameters are:

- `array`: A pointer to an array of integers.
- `size`: The size of the array.

The function description mentions that it prints the array after each swap. This can be helpful to visualize the sorting process.

```c
void selection_sort(int *array, size_t size)
{
        int *nsghir;
        size_t i, j;

        if (array == NULL || size < 2)
                return;
```
The `selection_sort` function begins by declaring some local variables: `nsghir`, `i`, and `j`. 

Next, the function checks if the `array` is `NULL` or if its size is less than 2. If either of these conditions is true, it means the array is either empty or has only one element, so it is already sorted, and the function simply returns without performing any sorting.

```c
        for (i = 0; i < size - 1; i++)
        {
                nsghir = array + i;
                for (j = i + 1; j < size; j++)
                        nsghir = (array[j] < *nsghir) ? (array + j) : nsghir;

                if ((array + i) != nsghir)
                {
                        swap(array + i, nsghir);
                        print_array(array, size);
                }
        }
}
```
The function proceeds with the Selection Sort algorithm.

The outer loop (for-loop) runs from `i = 0` to `i = size - 2`, representing the index of the element being considered for the current iteration. The reason for `size - 2` is that the last element is already in its correct position when all other elements have been sorted.

Within the outer loop, `nsghir` (pronounced as "nseghir") is initialized as a pointer to the element at index `i`. It is used to keep track of the smallest element found in the remaining unsorted part of the array.

The inner loop (another for-loop) runs from `j = i + 1` to `j = size - 1`, representing the index of the element being compared to the element at index `i`. The purpose of this loop is to find the smallest element in the unsorted part of the array.

If the element at index `j` is smaller than the element pointed to by `nsghir`, `nsghir` is updated to point to the element at index `j`. After the inner loop finishes, `nsghir` will point to the smallest element in the unsorted part of the array.

After finding the smallest element, the function checks if the current element (`array + i`) is already the smallest. If it's not, then it performs a swap using the `swap` function to move the smallest element to its correct position in the sorted part of the array. The `print_array` function is called to print the current state of the array after each swap.

The process continues until all elements are in their correct sorted positions, and the array is completely sorted in ascending order.
