#include "libft.h"
int	_ft_strlen(const char *s)
{
	int	ret;

	if (!s)
		return (0);
	ret = 0;
	while (s[ret])
		++ret;
	return (ret);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	ret;

	ret = ft_strlen(dest);
	if (ret > size)
		ret = size;
	ret += ft_strlen(src);
	if (size == 0)
		return (ret);
	while (*dest)
	{
		++dest;
		--size;
		if (!size)
			return (ret);
	}
	while (*src && size > 1)
	{
		*dest = *src;
		++dest;
		++src;
		--size;
	}
	*dest = '\0';
	return (ret);
}
