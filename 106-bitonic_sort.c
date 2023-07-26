#include "sort.h"
#include <stdio.h>

/**
 * printcheck - print a range
 * @array: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: Nothing
 */
void printcheck(int *array, int r1, int r2)
{
	int a;

	for (a = r1; a <= r2; a++)
	{
		if (a > r1)
			printf(", ");
		printf("%d", array[a]);
	}
	printf("\n");
}
/**
 * _swap - swap two elements in an array
 * @array: THe array to change the values
 * @i: A index
 * @j: Another index
 * @dir: Direction of the array
 * Return: Nothing
 */
void _swap(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}
/**
 * bitonic_merge - swap the elements to sort
 * @array: Array to sort
 * @low: The low element in the range to sort
 * @size: The size of the range to sort
 * @dir: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */
void bitonic_merge(int *array, int low, int size, int dir, const int r_size)
{
	int b = size, a = low;

	if (size > 1)
	{
		b = size / 2;

		for (a = low; a < low + b; a++)
			_swap(array, a, a + b, dir);

		bitonic_merge(array, low, b, dir, r_size);
		bitonic_merge(array, low + b, b, dir, r_size);
	}
}
/**
 * _sort - segmentate the array
 * @array: The array to sort
 * @low: The lowest element in each range
 * @size: Size of the range to sort
 * @dir: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */
void _sort(int *array, int low, int size, int dir, const int r_size)
{
	int b = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		printcheck(array, low, low + b - 1);

		b = size / 2;
		_sort(array, low, b, 1, r_size);

		_sort(array, low + b, b, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			printcheck(array, low, low + 2 * b - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			printcheck(array, low, low + 2 * b - 1);
		}
	}
}
/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_sort(array, 0, (int)size, up, r_size);
}
