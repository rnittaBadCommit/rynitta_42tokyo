#include "libft.h"

int	ft_count_digits(int n)
{
	int	ret;

	n = ft_abs(n);
	ret = 1;
	while (n > 9)
	{
		n /= 10;
		++ret;
	}
	return (ret);
}
