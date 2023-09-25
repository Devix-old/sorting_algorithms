#include "sort.h"

/**
 * insertion_sort - Sorts a subarray using insertion sort with a given gap.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @gap: Gap for comparing elements.
 */
void insertion_sort(int *array, size_t size, int gap)
{
    int temp, j;

    for (int i = gap; i < size; i++) {
        temp = array[i];
        j = i;

        while (j >= gap && array[j - gap] > temp) {
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
    int gap = 1;
    
    while (gap < (int)size / 3)
        gap = gap * 3 + 1;

    while (gap > 0) {
        printf("Step with gap %d: ", gap);
        print_array(array, size);
        insertion_sort(array, size, gap);
        gap /= 3;
    }
}
