/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:54:23 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:59:14 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
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
