#include "push_swap.h"

static void _set_ordinal_array(int *ordinal_array, t_cardinal_num *cardinal_array, size_t array_size)
{
	int i;

	i = 0;
	while (i < array_size)
	{
		ordinal_array[cardinal_array[i].index] = i;
		++i;
	}
}

static void check_duplicate(t_cardinal_num *cardinal_num_array, size_t array_size)
{
	size_t i;

	i = 0;
	while (i + 1 < array_size)
	{
		if (cardinal_num_array[i].num == cardinal_num_array[i + 1].num)
			err();
		++i;
	}
}

int *make_ordinal_array(int array_size, char **args)
{
	int *ret;
	t_cardinal_num *cardinal_num_array;

	ret = (int *)malloc(sizeof(int) * (array_size));
	if (!ret)
		exit(MALLOC_FAIL);
	cardinal_num_array = make_cardinal_num_array(array_size, args);

	print_cardinal_array(cardinal_num_array, array_size);

	sort_cardinal_num_array(cardinal_num_array, array_size);
	check_duplicate(cardinal_num_array, array_size);

	print_cardinal_array(cardinal_num_array, array_size);

	_set_ordinal_array(ret, cardinal_num_array, array_size);
	return (ret);
}
