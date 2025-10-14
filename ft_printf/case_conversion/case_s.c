#include "../ft_printf.h"

int	case_s(char *s, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = auto_flush_buffered_write(s);
		ret += print_n_c(' ', conversion_setting->width - ft_strlen(s));
	}
	else
	{
		ret = print_n_c(' ', conversion_setting->width - ft_strlen(s));
		ret += auto_flush_buffered_write(s);
	}
	return (ret);
}
