#include "../ft_printf.h"

int	case_s(char *s, t_conversion_setting *conversion_setting)
{
	int	ret;
	int	len_space;

	if (conversion_setting->precision >= 0 && (size_t)conversion_setting->precision < ft_strlen(s))
	{
		s[conversion_setting->precision] = '\0';
		len_space = conversion_setting->width - conversion_setting->precision;
	}
	else
		len_space = conversion_setting->width - ft_strlen(s);
	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
			ret = auto_flush_buffered_write(s);
			ret += print_n_c(' ', len_space);
	}
	else
	{
			ret = print_n_c(' ', len_space);
			ret += auto_flush_buffered_write(s);
	}
	return (ret);
}
