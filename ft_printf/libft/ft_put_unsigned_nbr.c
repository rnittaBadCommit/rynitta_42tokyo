/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:50:50 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:50:52 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_nbr(unsigned long long int n)
{
	char	buf[20];
	size_t	i;

	buf[19] = n % 10 + '0';
	i = 18;
	while (n >= 10)
	{
		n /= 10;
		buf[i] = '0' + n % 10;
		--i;
	}
	return (write(1, buf + i + 1, 19 - i));
}

int	ft_put_unsigned_nbr_base(unsigned long long int n, char *base)
{
	char	buf[64];
	size_t	i;
	size_t	len_base;

	len_base = ft_strlen(base);
	buf[63] = base[n % len_base];
	i = 62;
	while (n >= len_base)
	{
		n /= len_base;
		buf[i] = base[n % len_base];
		--i;
	}
	return (write(1, buf + i + 1, 63 - i));
}
