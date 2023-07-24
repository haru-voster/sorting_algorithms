/*
 * File: 3-quick_sort.c
 * Auth: haru-voster
 */

#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: First integer
 * @y: Second integer
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - Arrange a subset of integers in an @array
 * according to the Lomuto partition scheme.
 * @array: The array to be partitioned
 * @low: Starting index
 * @high: Ending index
 * @size: The size of @array
 *
 * Return: The final partition index
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int *pivot, top, bottom;

	pivot = array + high;
	for (top = bottom = low; bottom < high; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swap(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}
	if (array[top] > *pivot)
	{
		swap(array + top, pivot);
		print_array(array, size);
	}
	return (top);
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the @array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_scheme(array, 0, size - 1, size);
}

/**
 * lomuto_scheme - Use recursion to implement the quicksort algorithm
 * Using the Lomuto partition scheme
 * @array: Array of integers to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The size of @array
 */

void lomuto_scheme(int *array, int low, int high, size_t size)
{
	int pvt;

	if (high - low > 0)
	{
		pvt = lomuto_partition(array, low, high, size);
		lomuto_scheme(array, low, pvt - 1, size);
		lomuto_scheme(array, pvt + 1, high, size);
	}

}
