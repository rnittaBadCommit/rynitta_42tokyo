/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_hex_digits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:53:04 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:56:01 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hex_digits(long long int n)
{
	int	ret;

	if (n == LLONG_MIN)
		n = LLONG_MAX;
	n = ft_abs(n);
	ret = 1;
	while (n >= 16)
	{
		n /= 16;
		++ret;
	}
	return (ret);
}

int	ft_count_unsigned_hex_digits(unsigned long long int n)
{
	int	ret;

	ret = 1;
	while (n >= 16)
	{
		n /= 16;
		++ret;
	}
	return (ret);
}
