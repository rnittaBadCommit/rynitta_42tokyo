#include "libft.h"

void	ft_bzero(void *p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((char *)p)[i] = 0;
		++i;
	}
}
