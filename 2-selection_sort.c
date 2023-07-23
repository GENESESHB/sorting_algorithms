#include "sort.h"

/**
 *swap - Swap two integers in an array.
 *@a: The first integer to swap.
 *@b: The second integer to swap.
 */

void swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description:prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *nsghir;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

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
