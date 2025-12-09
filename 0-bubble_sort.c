#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: pointer to the array of integers to sort
 * @size: number of elements in the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j, tmp;
	int swap_on;

	for (i = 0; i < size - 1; i++)
	{
		swap_on = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);

				swap_on = 1;
			}
		}

		if (swap_on == 0)
			break;
	}
}
