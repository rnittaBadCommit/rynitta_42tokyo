#include "../ft_printf.h"

int	case_c(char c, t_conversion_setting *conversion_setting)
{
	int	ret;

	if (ft_is_flag_set(conversion_setting->flag, FLAG_MINUS))
	{
		ret = print_n_c(c, 1);
		ret += print_n_c(' ', conversion_setting->width - 1);
	}
	else
	{
		ret = print_n_c(' ', conversion_setting->width - 1);
		ret += print_n_c(c, 1);
	}
	return (ret);
}
