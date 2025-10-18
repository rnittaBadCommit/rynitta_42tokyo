/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:51:14 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:51:22 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_n_c(char c, int len)
{
	int		ret;

	ret = 0;
	while (len > 0)
	{
		ret += auto_flush_buffered_write(&c, 1);
		--len;
	}
	return (ret);
}
