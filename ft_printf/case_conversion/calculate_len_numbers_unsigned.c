#include "../ft_printf.h"

inline static int	_case_no_dot(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	digits;

	if (ft_strchr("idu", conversion_setting->conversion_type))	
		digits = ft_count_unsigned_digits(n);
	else
		digits = ft_count_unsigned_hex_digits(n);
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) && digits < conversion_setting->width)
		return (conversion_setting->width);
	return (digits);
}

inline static int	_case_dot(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	int	digits;

	if (n == 0)
		return (0);
	if (ft_strchr("idu", conversion_setting->conversion_type))		
		digits = ft_count_unsigned_digits(n);
	else
		digits = ft_count_unsigned_hex_digits(n);
	if (digits < conversion_setting->precision)
		digits = conversion_setting->precision;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_ZERO) && conversion_setting->width > digits)
		return (conversion_setting->width);
	return (digits);
}

int	calculate_len_numbers_unsigned(unsigned long long int n, t_conversion_setting *conversion_setting)
{
	if (ft_is_flag_set(conversion_setting->flag, FLAG_DOT))
		return (_case_dot(n, conversion_setting));
	else
		return (_case_no_dot(n, conversion_setting));
}
