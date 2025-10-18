/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:54:33 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:54:54 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	__print_symbol(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	if (n && ft_is_flag_set(conversion_setting->flag, FLAG_SHARP))
	{
		if (conversion_setting->conversion_type == 'x')
			return (auto_flush_buffered_putstr("0x"));
		else
			return (auto_flush_buffered_putstr("0X"));
	}
	return (0);
}

static int	_print_numbers(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) \
		&& conversion_setting->precision == 0)
		return (0);
	ret = __print_symbol(n, conversion_setting);
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) \
		&& conversion_setting->width > conversion_setting->precision)
		ret += print_n_c('0', calculate_len_numbers(n, conversion_setting) \
			- ft_count_unsigned_hex_digits(n));
	else
		ret += print_n_c('0', conversion_setting->precision \
			- ft_count_unsigned_hex_digits(n));
	ret += flush_buffer();
	if (conversion_setting->conversion_type == 'x')
		ret += ft_put_unsigned_nbr_base(n, "0123456789abcdef");
	else
		ret += ft_put_unsigned_nbr_base(n, "0123456789ABCDEF");
	return (ret);
}

int	case_xx(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_numbers(n, conversion_setting);
		ret += print_n_c(' ', conversion_setting->width \
			- calculate_len_numbers(n, conversion_setting));
	}
	else
	{
		ret = print_n_c(' ', conversion_setting->width \
			- calculate_len_numbers(n, conversion_setting));
		ret += _print_numbers(n, conversion_setting);
	}
	return (ret);
}
