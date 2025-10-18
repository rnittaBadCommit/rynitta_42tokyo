/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:49:43 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:54:15 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	_print_numbers(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) \
		&& conversion_setting->precision == 0)
		return (0);
	ret = 0;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) \
		&& conversion_setting->width > conversion_setting->precision)
		ret += print_n_c('0', calculate_len_numbers(n, conversion_setting) \
			- ft_count_unsigned_digits(n));
	else
		ret += print_n_c('0', conversion_setting->precision \
			- ft_count_unsigned_digits(n));
	ret += flush_buffer();
	ret += ft_put_unsigned_nbr(n);
	return (ret);
}

int	case_u(unsigned long long int n, t_conversion_setting *conversion_setting)
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
