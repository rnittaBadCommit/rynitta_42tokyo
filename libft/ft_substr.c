#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_ret;
	char	*ret;

	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	len_ret = len_s - start;
	if (len_ret > len)
		len_ret = len;
	ret = (char *)malloc(len_ret + 1);
	ft_memcpy(ret, s + start, len_ret);
	ret[len_ret] = '\0';
	return (ret);
}
