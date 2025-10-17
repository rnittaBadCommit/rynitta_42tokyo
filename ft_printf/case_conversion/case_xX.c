#include "../ft_printf.h"

static int	_calculate_len_space(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;
	int	len_numbers;

	ret = conversion_setting->width;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_SHARP) && n)
		ret -= 2;
	len_numbers = ft_count_unsigned_hex_digits(n);
	if (len_numbers < conversion_setting->precision)
		len_numbers = conversion_setting->precision;
	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		++ret;
	if (ret > len_numbers)
		ret -= len_numbers;
	else
		ret = 0;
	return (ret);
}

static int	_print_numbers(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		return (0);
	ret = print_n_c('0', conversion_setting->precision - ft_count_unsigned_hex_digits(n));
	ret += flush_buffer();
	if (conversion_setting->conversion_type == 'x')
		ret += ft_put_unsigned_nbr_base(n, "0123456789abcdef");
	else
		ret += ft_put_unsigned_nbr_base(n, "0123456789ABCDEF");
	return (ret);
}

static int	_print_symbol(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = 0;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_SHARP) && n)
	{
		if (conversion_setting->conversion_type == 'x')
			ret += auto_flush_buffered_putstr("0x");
		else
			ret += auto_flush_buffered_putstr("0X");
	}
	return (ret);
}

int	case_xX(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_symbol(n, conversion_setting);
		ret += _print_numbers(n, conversion_setting);
		ret += print_n_c(' ', _calculate_len_space(n, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
		{
			ret = _print_symbol(n, conversion_setting);
			ret += print_n_c('0', _calculate_len_space(n, conversion_setting));
		}
		else
		{
			ret = print_n_c(' ', _calculate_len_space(n, conversion_setting));
			ret += _print_symbol(n, conversion_setting);
		}
		ret += _print_numbers(n, conversion_setting);
	}
	return (ret);
}
