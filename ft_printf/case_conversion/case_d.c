#include "../ft_printf.h"

static int	_calculate_space_to_print(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = conversion_setting->width;
	if (n < 0)
		--ret;
	else if (ft_is_flag_set(conversion_setting->flag, FLAG_PLUS))
		--ret;
	else if (ft_is_flag_set(conversion_setting->flag, FLAG_SPACE))
		--ret;
	ret -= ft_count_digits(n);
	return (ret);
}

static int	_print_numbers(long long int n)
{
	int	ret;

	ret = 0;
	ret += flush_buffer();
	ret += ft_putnbr(n);
	return (ret);
}

static int	_print_symbol(long long int n, t_flag *flag)
{
	int	ret;
	
	ret = 0;
	if (n < 0)
	{	
		ret += auto_flush_buffered_write("-");
		n *= -1;
	}
	else if (ft_is_flag_set(*flag, FLAG_PLUS))
		ret += auto_flush_buffered_write("+");
	else if (ft_is_flag_set(*flag, FLAG_SPACE))
		ret += auto_flush_buffered_write(" ");
	return (ret);
}

int	case_di(int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_symbol(n, &conversion_setting->flag);
		ret += _print_numbers(ft_abs(n));
		ret += print_n_c(' ', _calculate_space_to_print(n, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
		{
			ret = _print_symbol(n, &conversion_setting->flag);
			ret += print_n_c('0', _calculate_space_to_print(n, conversion_setting));
		}
		else
		{
			ret = print_n_c(' ', _calculate_space_to_print(n, conversion_setting));
			ret += _print_symbol(n, &conversion_setting->flag);
		}
		ret += _print_numbers(ft_abs(n));
	}
	return (ret);
}
