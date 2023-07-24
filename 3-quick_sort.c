#include "sort.h"
#include "sort.h"

/**
 *swap - a function that swaps two integers.
 *@a: first integer.
 *@b: second integer to swap.
 *Return: void.
 */

void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 *lomuto_partition - a function to do the partition of the array
 *using lomuto partition algorithm.
 *@array: the array to be partitioned.
 *@l: the index of the first element of the array's part to be partitioned.
 *@h: the index of the last  element of the array's part to be partitioned.
 *@size: the size of the whole array.
 *Return: the index of the pivot.
 */

unsigned int lomuto_partition(int *array, int l, int h, size_t size)
{
	int i, j, pivot;

	pivot = array[h];
	i = l - 1;
	j = h;

	while (i < j)
	{
		do
		{
			i++;
		}

		while (array[i] < pivot);

		do
		{
			j--;
		}

		while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i], &array[h]);
	print_array(array, size);
	return (i);
}

/**
 *quicksort - it is kind of wrapper of quick_sort function.
 *@array: the array to be sorted.
 *@l: the index of the first element of the array's part to be sorted.
 *@h: the index of the last  element of the array's part to be sorted.
 *@size: the size of the whole array.
 *Return: void.
 */

void quicksort(int *array, int l, int h, size_t size)
{
	int j;

	if (l < h)
	{
		j = lomuto_partition(array, l, h, size);
		if (j > 0)
			quicksort(array, l, j - 1, size);
		quicksort(array, j + 1, h, size);
	}
}

/**
 *quick_sort - a function that sorts an array using
 *the Quick sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	quicksort(array, 0, size - 1, size);
}
