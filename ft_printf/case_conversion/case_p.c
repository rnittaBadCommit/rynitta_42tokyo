/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:47:25 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:48:42 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

#include "../ft_printf.h"

static int	__print_symbol(unsigned long long int n)
{
	if (n)
		return (auto_flush_buffered_putstr("0x"));
	return (0);
}

static int	_print_numbers(unsigned long long int n)
{
	int	ret;

	ret = __print_symbol(n);
	ret += flush_buffer();
	if (!n)
		ret += auto_flush_buffered_putstr("(nil)");
	else
		ret += ft_put_unsigned_nbr_base(n, "0123456789abcdef");
	return (ret);
}

int	case_p(void *p, t_conversion_setting *conversion_setting)
{
	int						ret;
	unsigned long long int	n;

	n = (unsigned long long int)p;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_numbers(n);
		ret += print_n_c(' ', conversion_setting->width \
			- calculate_len_numbers_unsigned(n, conversion_setting));
	}
	else
	{
		ret = print_n_c(' ', conversion_setting->width \
			- calculate_len_numbers_unsigned(n, conversion_setting));
		ret += _print_numbers(n);
	}
	return (ret);
}
