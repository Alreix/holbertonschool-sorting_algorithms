#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursively sorts an array using Quick sort
 *
 * @array: Pointer to the array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total size of the array (needed for printing)
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);

		_quick_sort(array, low, p - 1, size);
		_quick_sort(array, p + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions an array using Lomuto's scheme
 *
 * @array: Pointer to the array to partition
 * @low: Starting index
 * @high: Ending index (pivot)
 * @size: Total size of the array
 *
 * Return: Final position of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
