/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:09 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:51:22 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long long int n)
{
	char			buf[11];
	int				i;

	if (n == LLONG_MIN)
		return (write(1, "-9223372036854775807", 20));
	if (n < 0)
		n *= -1;
	buf[10] = '0' + n % 10;
	i = 9;
	while (n >= 10)
	{
		n /= 10;
		buf[i] = '0' + n % 10;
		--i;
	}
	if (n < 0)
	{
		buf[i] = '-';
		--i;
	}
	return (write(1, buf + i + 1, 10 - i));
}

int	ft_putnbr_base(int n, char *base)
{
	long long int	lln;
	char			buf[33];
	int				i;
	int				len_base;

	len_base = ft_strlen(base);
	lln = n;
	if (n < 0)
		lln *= -1;
	buf[32] = base[lln % len_base];
	i = 31;
	while (lln >= len_base)
	{
		lln /= len_base;
		buf[i] = base[lln % len_base];
		--i;
	}
	if (n < 0)
	{
		buf[i] = '-';
		--i;
	}
	return (write(1, buf + i + 1, 32 - i));
}
