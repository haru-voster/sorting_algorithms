/**
 * File name:3-quick_sort.c
 * Auth: Haru-voster
 */
#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lw: lower
 * @hg: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lw, int hg, size_t size)
{
	int i = lw - 1, j = lw;
	int pivot = array[hg], aux = 0;

	for (; j < hg; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hg])
	{
		aux = array[i + 1];
		array[i + 1] = array[hg];
		array[hg] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lw: lower
 * @hg:higher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lw, int hg, size_t size)
{
	int pivot;

	if (lw < hg)
	{
		pivot = partition(array, lw, hg, size);
		quick_s(array, lw, pivot - 1, size);
		quick_s(array, pivot + 1, hg, size);
	}
}
