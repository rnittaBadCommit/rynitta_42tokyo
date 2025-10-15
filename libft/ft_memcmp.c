#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	while (n > 0 && (*(unsigned char *)buf1 == *(unsigned char *)buf2))
	{
		++buf1;
		++buf2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)buf1 - *(unsigned char *)buf2);
}
