#include "../ft_printf.h"

static int	_calculate_space_to_print(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	ret = conversion_setting->width;
	ret -= ft_count_hex_digits(n);
	return (ret);
}

static int	_print_numbers(long long int n)
{
	int	ret;

	ret = flush_buffer();
	ret += ft_put_number(n);	
	return (ret);
}

int	case_u(long long int n, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = _print_numbers(n);
		ret += print_n_c(' ', _calculate_space_to_print(n, conversion_setting));
	}
	else
	{
		if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO))
			ret = print_n_c('0', _calculate_space_to_print(n, conversion_setting));
		else
			ret = print_n_c(' ', _calculate_space_to_print(n, conversion_setting));
		ret += _print_numbers(n);
	}
	return (ret);
}
