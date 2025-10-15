#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)buf == (unsigned char)c)
			return ((void *)buf);
		--n;
		++buf;
	}
	return (0);
}
