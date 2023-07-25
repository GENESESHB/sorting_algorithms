#include "sort.h"

/**
 *swap - a function that swaps two integers.
 *@a: first integer to swap.
 *@b: second integer to swap.
 *
 * Return: void.
 */

void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * shell_sort - a function that sorts an array using
 * shell sort algorithm .
 * @array: the array to be sorted.
 * @size: the size of the array.
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1, n;
	int i, j;

	n = size;

	while (gap < n)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (j = gap; j < n; j++)
		{
			for (i = j - gap; i >= 0 && array[i] > array[i + gap]; i -= gap)
			{
				swap(&array[i], &array[i + gap]);
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
