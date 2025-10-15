#include "libft.h"

void	ft_striteri(char const *s, char (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s);
		++i;
	}
}
