#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: pointer to the array of integers to sort
 * @size: number of elements in the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index_min;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		index_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index_min = j;
			}
		}

		if (index_min != i)
		{
			array[index_min] = array[i];
			array[i] = min;

			print_array(array, size);
		}
	}
}
