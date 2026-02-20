#include "cardinal_num.h"

t_cardinal_num *make_cardinal_num_array(int array_size, char **args)
{
	t_cardinal_num *ret;
	int i;

	ret = (t_cardinal_num *)malloc(sizeof(t_cardinal_num) * (array_size));
	if (!ret)
		exit(MALLOC_FAIL);
	i = 0;
	while (i < array_size)
	{
		ret[i].num = ft_atoi(args[i]);
		ret[i].index = i;
		++i;
	}
	return (ret);
}
