#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void *ret;

	ret = (void *)malloc(size * n);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * n);
	return (ret);
}
