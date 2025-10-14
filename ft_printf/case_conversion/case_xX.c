#include "../ft_printf.h"

static int	_calculate_space_to_print(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = conversion_setting->width;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_SHARP) && n)
		ret -= 2;
	ret -= ft_count_hex_digits(n);
	return (ret);
}

static int	_print_numbers(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = flush_buffer();
	if (conversion_setting->conversion_type == 'x')
		ret  += ft_putnbr_base(n, "0123456789abcdef");
	else
		ret  += ft_putnbr_base(n, "0123456789ABCDEF");
	return (ret);
}

static int	_print_symbol(long long int n, t_flag *flag)
{
	int	ret;

	ret = 0;
	if (ft_is_flag_set(*flag, FLAG_SHARP) && n)
		ret += auto_flush_buffered_write("0x");
	return (ret);
}

int	case_xX(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_symbol(n, &conversion_setting->flag);
		ret += _print_numbers(n, conversion_setting);
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
		ret += _print_numbers(n, conversion_setting);
	}
	return (ret);
}
