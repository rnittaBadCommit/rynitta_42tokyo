#include "../ft_printf.h"

int	case_s(char *s, t_conversion_setting *conversion_setting)
{
	int		ret;
	size_t	len_space;
	size_t	len_str;

	if (!s)
		s = "(null)";
	len_str = ft_strlen(s);
	if (ft_is_flag_set(conversion_setting->flag, FLAG_DOT) && conversion_setting->precision >= 0 && (size_t)conversion_setting->precision < len_str)
	{
		len_str = conversion_setting->precision;
		len_space = conversion_setting->width - conversion_setting->precision;
	}
	else
		len_space = conversion_setting->width - len_str;
	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
			ret = auto_flush_buffered_write(s, len_str);
			ret += print_n_c(' ', len_space);
	}
	else
	{
			ret = print_n_c(' ', len_space);
			ret += auto_flush_buffered_write(s, len_str);
	}
	return (ret);
}
