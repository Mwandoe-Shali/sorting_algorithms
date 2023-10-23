#include "sort.h"

/*
 * selection_sort - Sorta an array using the Selection Sort Algorithm
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
    int temp;
    size_t i, j, min;

    if (!array || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            print_array(array, size);
        }
    }
}
