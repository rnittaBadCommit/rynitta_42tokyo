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

int	ft_count_hex_digits(int n)
{
	int	ret;

	n = ft_abs(n);
	ret = 1;
	while (n > 15)
	{
		n /= 16;
		++ret;
	}
	return (ret);
}
