#ifdef DEBUG

#include "push_swap.h"
#include <stdio.h>

void print_ordinal_array(int *ordinal_array, size_t array_size)
{
	size_t i;

	i = 0;
	while (i < array_size)
	{
		printf("%d ", ordinal_array[i]);
		++i;
	}
	printf("\n");
}

void print_cardinal_array(t_cardinal_num *cardinal_array, size_t array_size)
{
	size_t i;

	i = 0;
	while (i < array_size)
	{
		printf("%d ", cardinal_array[i].num);
		++i;
	}
	i = 0;
	while (i < array_size)
	{
		printf("%d ", cardinal_array[i].index);
		++i;
	}
	printf("\n");
}

#endif
