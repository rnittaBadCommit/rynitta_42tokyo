/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 04:58:47 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 04:58:57 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	void	*save;

	if (buf1 < buf2)
		return (ft_memcpy(buf1, buf2, n));
	save = buf1;
	while (n > 0)
	{
		*(char *)(buf1 + n - 1) = *(char *)(buf2 + n - 1);
		--n;
	}
	return (save);
}
