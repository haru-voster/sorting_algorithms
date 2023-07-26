#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * copy - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 *
 * Return: No Return
 */
void copy(int *src, int *dst, int size)
{
	int a;

	for (a = 0; a < size; a++)
		dst[a] = src[a];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: first set of data
 * @buff: second set of data
 * @minL: lower range of first set of data
 * @maxL: upper range of first set of data
 * @minR: lower range of second set of data
 * @maxR: upper range of second set of data
 *
 * Return: No Return
 */
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int a = minL, b = minR, c = minL;

	while (a <= maxL || b <= maxR)

		if (a <= maxL && b <= maxR)
			if (buff[a] <= buff[b])
				array[c] = buff[a], c++, a++;
			else
				array[c] = buff[b], c++, b++;

		else if (a > maxL && b <= maxR)
			array[c] = buff[b], c++, b++;
		else
			array[c] = buff[a], c++, a++;
}
/**
 * printcheck - prints an array in a given range
 *
 * @array: array of data to be print
 * @arr1: start of range
 * @arr2: end of range
 *
 * Return: No Return
 */
void printcheck(int *array, int arr1, int arr2)
{
	int a;

	for (a = arr1; a <= arr2; a++)
	{
		if (a > arr1)
			printf(", ");
		printf("%d", array[a]);
	}
	printf("\n");
}
/**
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 *
 * Return: No Return
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}
