#include "libft.h"

char			*ft_strdup(const char *str)
{
	size_t	len;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	return (ft_memcpy(ret, str, len + 1));
}
