#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort.
 * @array: The input array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Find the maximum value in the input array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create and initialize the counting array */
	int *counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;

	for (int i = 0; i <= max; i++)
		counting_array[i] = 0;

	/* Populate the counting array with counts of each value */
	for (size_t i = 0; i < size; i++)
	{
		counting_array[array[i]]++;
	}

	/* Reconstruct the sorted array from the counting array */
	int *sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}

	int sorted_index = 0;
	for (int i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			sorted_array[sorted_index] = i;
			sorted_index++;
			counting_array[i]--;
		}
	}

	/* Copy the sorted array back to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = sorted_array[i];

	/* Free dynamically allocated memory */
	free(counting_array);
	free(sorted_array);
}
