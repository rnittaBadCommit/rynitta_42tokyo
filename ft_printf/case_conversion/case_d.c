#include "../ft_printf.h"

static int	_calculate_len_space(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;
	int	len_numbers;

	ret = conversion_setting->width;
	if (n < 0)
		--ret;
	else if (ft_is_flag_set(conversion_setting->flag, FLAG_PLUS))
		--ret;
	else if (ft_is_flag_set(conversion_setting->flag, FLAG_SPACE))
		--ret;
	len_numbers = ft_count_digits(n);
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

static int	_print_numbers(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n < 0)
		n *= -1;
	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		return (0);
	ret = 0;
	ret += print_n_c('0', conversion_setting->precision - ft_count_digits(n));
	ret += flush_buffer();
	ret += ft_put_unsigned_nbr(n);
	return (ret);
}

static int	_print_symbol(long long int n, t_flag *flag)
{
	int	ret;
	
	ret = 0;
	if (n < 0)
		ret += auto_flush_buffered_putstr("-");
	else if (ft_is_flag_set(*flag, FLAG_PLUS))
		ret += auto_flush_buffered_putstr("+");
	else if (ft_is_flag_set(*flag, FLAG_SPACE))
		ret += auto_flush_buffered_putstr(" ");
	return (ret);
}

int	case_di(int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_symbol(n, &conversion_setting->flag);
		ret += _print_numbers(ft_abs(n), conversion_setting);
		ret += print_n_c(' ', _calculate_len_space(n, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
		{
			ret = _print_symbol(n, &conversion_setting->flag);
			ret += print_n_c('0', _calculate_len_space(n, conversion_setting));
		}
		else
		{
			ret = print_n_c(' ', _calculate_len_space(n, conversion_setting));
			ret += _print_symbol(n, &conversion_setting->flag);
		}
		ret += _print_numbers(ft_abs(n), conversion_setting);
	}
	return (ret);
}
