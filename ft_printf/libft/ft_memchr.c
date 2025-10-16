/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:53:55 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:54:50 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
