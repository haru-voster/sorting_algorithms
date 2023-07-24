
/*
 * File: 2-selection_sort.c
 * Auth: Haru-voster
 */
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascedning order
 *  using the selection sort algorithm.
 *@array: The array to be sorted
 *@size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, min, ytmp;
	int xtmp;

	/* loop through the entire array */
	for (x = 0; x < size - 1; x++)
	{
		/*
		 * Find the smallest element in the unsorted array[x...size-1]
		 * Assume the first element is the minimum
		 */
		min = x;
		/* Compare against elements after a to find the smallest */
		for (y =  x+ 1;  y< size; y++)
		{

			/* if this element is smaller, then it is the new smallest */
			if (array[y] < array[min])
			{
				/* found the new smallest; remember the index */
				min = y;
			}
		}
		/* swap */
		if (min != x)
		{
			xtmp = array[x]; /*
					  * Save the value at index a to be swapped
					  * with the smallest element later
					  */
			ytmp = min; /* Save the samllest elements index before swapping */
			array[x] = array[min];
			array[ytmp] = xtmp;
			print_array(array, size);
		}
	}
}
