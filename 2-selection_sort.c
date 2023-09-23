#include "sort.h"
/**
 * selection_sort - this function sort an array using selection sort
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex, temp;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}
		if ((int)i != array[minIndex])
		{
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
		print_array(array, size);
	}
}
