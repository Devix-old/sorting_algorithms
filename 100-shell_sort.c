#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array containing the elements
 * @a: Index of the first integer to be swapped
 * @b: Index of the second integer to be swapped
 */
void swap(int *array, int a, int b)
{
	int tmp;

	if (array[a] != array[b])
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}

/**
 * shell_sort - Sorts an array of integers using Shell sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0, i, j;

	if (size < 2)
	{
		return;
	}
	while (h <= size / 3)
	{
		h = h * 3 + 1;
	}
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
			{
				swap(array, j, j - h);
			}
		}
		h /= 3;
		print_array(array, size);
	}
}
