#include "ft_libft.h"

int	ft_findc(char *s, char c)
{
	int	ret;

	ret = 0;
	while (s[ret])
	{
		if (s[ret] == c)
			return (ret);
		++ret;
	}
	return (-1);
}
