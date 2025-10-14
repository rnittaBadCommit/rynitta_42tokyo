#include "ft_libft.h"

void	ft_memzero(void *p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((char *)p)[i] = 0;
		++i;
	}
}
