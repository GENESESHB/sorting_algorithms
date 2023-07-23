#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


void swap(int *a, int *b)
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
}


void bubble_sort(int *array, size_t size)
{
	size_t i,j;

	if (array == NULL || size == 0)
		return;

    for (i = size - 1; i > 0; i--)
    {
        for (j = 1; j <= i; j++)
	{
		if (array[j - 1] > array[j])
			swap(&array[j - 1], &array[j]);
		print_array(array, size);
	}
    }
}
