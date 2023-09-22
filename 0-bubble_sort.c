#include <stdio.h>
#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp = 0;
	bool swap = true;

	for (i = 0; i < size; i++)
	{
		swap = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
