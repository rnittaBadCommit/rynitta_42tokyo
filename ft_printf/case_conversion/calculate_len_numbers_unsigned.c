/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_len_numbers_unsigned.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:44:18 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:46:00 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

inline static int	_case_no_dot(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	int	digits;

	if (ft_strchr("idu", conversion_setting->conversion_type))
		digits = ft_count_unsigned_digits(n);
	else if (conversion_setting->conversion_type == 'p')
	{
		if (n == 0)
			digits = ft_strlen("(nil)");
		else
			digits = ft_strlen("0x") + ft_count_unsigned_hex_digits(n);
	}
	else
		digits = ft_count_unsigned_hex_digits(n);
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) \
		&& digits < conversion_setting->width)
		digits = conversion_setting->width;
	return (digits);
}

inline static int	_case_dot(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	int	digits;

	if (n == 0 && conversion_setting->precision == 0)
		return (0);
	if (ft_strchr("idu", conversion_setting->conversion_type))
		digits = ft_count_unsigned_digits(n);
	else
		digits = ft_count_unsigned_hex_digits(n);
	if (digits < conversion_setting->precision)
		digits = conversion_setting->precision;
	return (digits);
}

int	calculate_len_numbers_unsigned(unsigned long long int n, \
	t_conversion_setting *conversion_setting)
{
	if (ft_is_flag_set(conversion_setting->flag, FLAG_DOT))
		return (_case_dot(n, conversion_setting));
	else
		return (_case_no_dot(n, conversion_setting));
}
