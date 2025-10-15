/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:53:39 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:56:30 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_count_digit(long long int n)
{
	size_t	ret;

	ret = 1;
	while (n > 9)
	{
		n /= 10;
		++ret;
	}
	return (ret);
}

void	_fill_numbers(char *dest, long long int lln, size_t len_dest)
{
	if (lln == 0)
	{
		dest[0] = '0';
		return ;
	}
	while (lln)
	{
		dest[len_dest - 1] = lln % 10 + '0';
		lln /= 10;
		--len_dest;
	}
}

char	*ft_itoa(int n)
{
	char			*ret;
	long long int	lln;
	size_t			len_ret;

	lln = n;
	if (n < 0)
		lln *= -1;
	len_ret = (n < 0) + _count_digit(lln);
	ret = (char *)malloc(len_ret + 1);
	if (!ret)
		return (ret);
	if (n < 0)
		ret[0] = '-';
	_fill_numbers(ret, lln, len_ret);
	return (ret);
}
