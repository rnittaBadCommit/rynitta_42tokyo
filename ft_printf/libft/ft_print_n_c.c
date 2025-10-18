#include "../ft_printf.h"

int	print_n_c(char c, int len)
{
	int		ret;

	ret = 0;
	while (len > 0)
	{
		ret += auto_flush_buffered_write(&c, 1);
		--len;
	}
	return (ret);
}
