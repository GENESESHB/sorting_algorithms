#include <stdio.h>
#include <stdlib.h>
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
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

/**
 *bubble_sort - a function that sorts an array using
 *using bubble sort algorithm.
 *@array: the array to be sorted.
 *@size: the size of the array.
 *Return: void.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size == 0)
		return;

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
