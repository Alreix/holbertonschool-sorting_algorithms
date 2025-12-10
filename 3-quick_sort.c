#include "sort.h"

/**
 * _quick_sort - recursively sorts a partition of an array
 *
 * @array: pointer to the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: total size of the array (for print_array)
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
 * lomuto_partition - partitions an array using Lomuto's scheme
 *
 * @array: pointer to the array
 * @low: starting index
 * @high: ending index (pivot)
 * @size: total size of the array
 *
 * Return: final index of the pivot
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

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using Quick sort (Lomuto partition scheme)
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}
