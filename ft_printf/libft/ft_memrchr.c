# include "libft.h"

void	*ft_memrchr(const void *p, int c, size_t size)
{
	size_t	i;
	const void	*ret;

	ret = NULL;
	i = 0;
	while (i < size)
	{
		if (((char *)p)[i] == (char)c)
			ret = p + i;
		++i;
	}
	return ((void *)ret);
}
