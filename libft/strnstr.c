/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 03:00:35 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 03:00:43 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	len_to_find_;

	len_to_find_ = ft_strlen(to_find);
	if (len < len_to_find_)
		return (NULL);
	len -= len_to_find_ - 1;
	while (*str && len)
	{
		if (ft_strncmp(str, to_find, len_to_find_) == 0)
			return (str);
		++str;
		--len;
	}
	return (NULL);
}
