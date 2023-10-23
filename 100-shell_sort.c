#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using the Shell sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    /* Calculate initial gap using the Knuth sequence */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            /* Store the current element */
            temp = array[i];
            j = i;

            /* Compare and shift elements with the given gap */
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            /* Place the stored element in the right position */
            array[j] = temp;
        }

        /* Reduce the gap for the next iteration */
        gap = (gap - 1) / 3;

        /* Print the array after each iteration */
        print_array(array, size);
    }
}
