/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:54:29 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 05:31:12 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
