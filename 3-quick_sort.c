#include "sort.h"

void swap_elements(int *element1, int *element2);
int hoare_partition(int *arr, size_t size, int low, int high);
void hoare_quick_sort(int *arr, size_t size, int low, int high);
void custom_quick_sort(int *arr, size_t size);

/**
 * swap_elements - Swap two elements in an array.
 * @element1: The first element to swap.
 * @element2: The second element to swap.
 */
void swap_elements(int *element1, int *element2)
{
	int temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

/**
 * lomuto_sort_partition - Partition a segment of an array using
 * the lomuto scheme.
 * @arr: The array to partition.
 * @size: The size of the array.
 * @low: The low index of the segment.
 * @high: The high index of the segment.
 *
 * Return: The final partition index.
 */
int lomuto_sort_partition(int *arr, size_t size, int low, int high)
{
	int pivot = arr[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
		{
			return (j);
		}

		swap_elements(&arr[i], &arr[j]);
		print_array(arr, size);
	}
}

/**
 * lomuto_quick_sort - Implement the quicksort algorithm using
 * the lomuto scheme.
 * @arr: The array to sort.
 * @size: The size of the array.
 * @low: The low index of the segment to sort.
 * @high: The high index of the segment to sort.
 *
 * Description: This function sorts the given segment of the array recursively.
 */
void lomuto_quick_sort(int *arr, size_t size, int low, int high)
{
	if (low < high)
	{
		int partition_index = lomuto_sort_partition(arr, size, low, high);

		lomuto_quick_sort(arr, size, low, partition_index);
		lomuto_quick_sort(arr, size, partition_index + 1, high);
	}
}

/**
 * quick_sort  - Sort an array of integers in ascending order
 * using the custom quicksort algorithm with the Hoare partition scheme.
 * @arr: The array of integers to sort.
 * @size: The size of the array.
 *
 * Description: This function initiates the quicksort process.
 * It prints the array after each swap of two elements.
 */
void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}

	lomuto_quick_sort(arr, size, 0, size - 1);
}
