#include "../ft_printf.h"

static int	_calculate_len_space(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (n == 0)
		return (conversion_setting->width - ft_strlen("(nil)"));
	ret = conversion_setting->width;
	ret -= 2;
	ret -= ft_count_unsigned_hex_digits(n);
	return (ret);
}

static int	_print_numbers(unsigned long long int n)
{
	int	ret;

	if (n == 0)
		return (auto_flush_buffered_putstr("(nil)"));	
 	ret = flush_buffer();
	ret  += ft_put_unsigned_nbr_base(n, "0123456789abcdef");
	return (ret);
}

static int	_print_symbol(void *p)
{
	int	ret;

	ret = 0;
	if (p != NULL)
		ret = auto_flush_buffered_putstr("0x");
	return (ret);
}

int	case_p(void *p, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_symbol(p);
		ret += _print_numbers((unsigned long long int)p);
		ret += print_n_c(' ', _calculate_len_space((unsigned long long int)p, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
		{
			ret = _print_symbol(p);
			ret += print_n_c('0', _calculate_len_space((unsigned long long int)p, conversion_setting));
		}
		else
		{
			ret = print_n_c(' ', _calculate_len_space((unsigned long long int)p, conversion_setting));
			ret += _print_symbol(p);
		}
		ret += _print_numbers((unsigned long long int)p);
	}
	return (ret);
}
