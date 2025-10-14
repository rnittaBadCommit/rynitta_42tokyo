#include "ft_libft.h"

int	ft_count_hex_digits(int n)
{
	int	ret;

	n = ft_abs(n);
	ret = 1;
	while (n > 15)
	{
		n /= 16;
		++ret;
	}
	return (ret);

}