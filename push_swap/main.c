#include "push_swap.h"

bool is_sorted(int *ordinal_array, size_t array_size)
{
	size_t i;

	i = 0;
	while (i + 1 < array_size)
	{
		if (ordinal_array[i] > ordinal_array[i + 1])
			return (false);
		++i;
	}
	return (true);
}

int main(int argc, char **argv)
{
	int *ordinal_array;
	t_list list;

	check_args(argc, argv);
	ordinal_array = make_ordinal_array(argc - 1, argv + 1);
	print_ordinal_array(ordinal_array, argc - 1);
	if (is_sorted(ordinal_array, argc - 1))
		return (0);
	list = make_ordinal_list();
	main_process(ordinal_array, argc - 1);
}
