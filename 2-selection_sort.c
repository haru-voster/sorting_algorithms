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
	size_t a, b, jmin, jtmp;
	int itmp;

	/* loop through the entire array */
	for (a = 0; a < size - 1; a++)
	{
		/*
		 * Find the smallest element in the unsorted array[a...size-1]
		 * Assume the first element is the minimum
		 */
		jmin = a;
		/* Compare against elements after a to find the smallest */
		for (b = a + 1; b < size; b++)
		{

			/* if this element is smaller, then it is the new smallest */
			if (array[b] < array[jmin])
			{
				/* found the new smallest; remember the index */
				jmin = b;
			}
		}
		/* swap */
		if (jmin != a)
		{
			itmp = array[a]; /*
					  * Save the value at index a to be swapped
					  * with the smallest element later
					  */
			jtmp = jmin; /* Save the samllest elements index before swapping */
			array[a] = array[jmin];
			array[jtmp] = itmp;
			print_array(array, size);
		}
	}
}
