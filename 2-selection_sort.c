/*
 * File: 2-selection_sort.c
 * Auth: haru-voster
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
	size_t x, y, jmin, jtmp;
	int itmp;

	/* loop through the entire array */
	for (x = 0; x < size - 1; x++)
	{
		/*
		 * Find the smallest element in the unsorted array[a...size-1]
		 * Assume the first element is the minimum
		 */
		jmin = x;
		/* Compare against elements after a to find the smallest */
		for (b = x + 1; y < size; y++)
		{

			/* if this element is smaller, then it is the new smallest */
			if (array[y] < array[jmin])
			{
				/* found the new smallest; remember the index */
				jmin = y;
			}
		}
		/* swap */
		if (jmin != x)
		{
			itmp = array[y]; /*
					  * Save the value at index a to be swapped
					  * with the smallest element later
					  */
			jtmp = jmin; /* Save the samllest elements index before swapping */
			array[x] = array[jmin];
			array[jtmp] = itmp;
			print_array(array, size);
		}
	}
}
