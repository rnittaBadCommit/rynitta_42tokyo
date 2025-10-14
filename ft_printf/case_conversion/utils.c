#include "../ft_printf.h"

int	print_n_c(char c, int len)
{
	int		ret;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	ret = 0;
	while (len > 0)
	{
		ret += auto_flush_buffered_write(s);
		--len;
	}
	return (ret);
}
