#include "sort.h"

/**
 * insertion_sort - Sorts a subarray using insertion sort with a given gap.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @gap: Gap for comparing elements.
 */
void insertion_sort(int *array, size_t size, size_t gap)
{
	int temp;
	size_t j, i;

	for (i = gap; i < size; i++)
	{
		temp = array[i];
		j = i;

		while (j >= gap && array[j - gap] > temp)
		{
			array[j] = array[j - gap];
			j -= gap;
		}

		array[j] = temp;
	}
}

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              with the Knuth sequence.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		print_array(array, size);
		insertion_sort(array, size, gap);
		gap /= 3;
	}
}
