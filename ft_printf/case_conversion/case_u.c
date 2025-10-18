#include "../ft_printf.h"

static int	_calculate_len_space(unsigned int n, t_conversion_setting *conversion_setting)
{
	int	ret;
	int	len_numbers;

	ret = conversion_setting->width;
	len_numbers = ft_count_unsigned_digits(n);
	if (len_numbers < conversion_setting->precision)
		len_numbers = conversion_setting->precision;
	ret -= len_numbers;
	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		++ret;
	return (ret);
}

static int	_print_numbers(unsigned int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		return (0);
	ret = flush_buffer();
	ret += ft_put_unsigned_nbr(n);	
	return (ret);
}

int	case_u(unsigned int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = print_n_c('0', conversion_setting->precision - ft_count_unsigned_digits(n));
		ret += _print_numbers(n, conversion_setting);
		ret += print_n_c(' ', _calculate_len_space(n, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
			ret = print_n_c('0', _calculate_len_space(n, conversion_setting));
		else
			ret = print_n_c(' ', _calculate_len_space(n, conversion_setting));
		ret += print_n_c('0', conversion_setting->precision - ft_count_unsigned_digits(n));
		ret += _print_numbers(n, conversion_setting);
	}
	return (ret);
}
