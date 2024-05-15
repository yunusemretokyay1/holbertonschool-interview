#include "search_algos.h"

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (recursive_search(array, 0, (int)(size - 1), value));
}

int recursive_search(int *array, int first, int last, int value)
{
	int mid, i;

	if (first > last)
		return (-1);

	mid = (first + last) / 2;

	if (array[mid] == value && first == last)
		return (mid);

	printf("Searching in array: ");

	i = first;
	while (i <= last)
	{
		if (i != first)
		{
			printf(", ");
		}
		printf("%d", array[i]);
		if (i == last)
			printf("\n");

		i++;
	}
	if (array[mid] >= value)
		return (recursive_search(array, first, mid, value));
	return (recursive_search(array, mid + 1, last, value));
}