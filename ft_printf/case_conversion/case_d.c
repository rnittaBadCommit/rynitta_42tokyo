#include "../ft_printf.h"

static int	_print_numbers(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n < 0)
		n *= -1;
	if (n == 0 && ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision == 0)
		return (0);
	ret = 0;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) && conversion_setting->width > conversion_setting->precision)
		ret += print_n_c('0', conversion_setting->width - ft_count_digits(n));
	else
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

int	_case_minus(int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = _print_symbol(n, &conversion_setting->flag);
	ret += _print_numbers(ft_abs(n), conversion_setting);
	ret += print_n_c(' ', conversion_setting->width - calculate_len_numbers(n, conversion_setting));
	return (ret);
}

int	_case_no_minus(int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
	{
		ret = print_n_c(' ', conversion_setting->width - calculate_len_numbers(n, conversion_setting));
		ret += _print_symbol(n, &conversion_setting->flag);
	}
	else
	{
		ret = print_n_c(' ', conversion_setting->width - calculate_len_numbers(n, conversion_setting));
		ret += _print_symbol(n, &conversion_setting->flag);
	}
	ret += _print_numbers(ft_abs(n), conversion_setting);
	return (ret);
}

#include <stdio.h>
int	case_di(int n, t_conversion_setting *conversion_setting)
{
	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
		return (_case_minus(n, conversion_setting));
	else
		return (_case_no_minus(n, conversion_setting));
}
