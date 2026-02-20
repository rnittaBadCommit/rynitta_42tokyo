#include "cardinal_num.h"

static inline void _swap_cardinal_num(t_cardinal_num *a, t_cardinal_num *b)
{
	t_cardinal_num tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_cardinal_num_array(t_cardinal_num *cardinal_num_array, size_t array_size)
{
	size_t i;
	bool is_sorted;

	is_sorted = false;
	while (is_sorted == false)
	{
		is_sorted = true;
		i = 0;
		while (i + 1 < array_size)
		{
			if (cardinal_num_array[i].num > cardinal_num_array[i + 1].num)
			{
				_swap_cardinal_num(&cardinal_num_array[i], &cardinal_num_array[i + 1]);
				is_sorted = false;
			}
			++i;
		}
		--array_size;
	}
}
