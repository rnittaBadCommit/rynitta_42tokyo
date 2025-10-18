/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:21 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:55:32 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *p, int c, size_t size)
{
	size_t		i;
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
