#include "../ft_printf.h"

static const char	*_load_flags(const char *s, t_flag *flag)
{
	int	i_conversion_flag;

	while (*s)
	{
		i_conversion_flag = ft_findc(FLAG_CHARACTERS, *s);
		if (i_conversion_flag == -1)
			return (s);
		*flag |= 1 << i_conversion_flag;
		++s;
	}
	return (NULL);
}

static const char	*_load_width(const char *s, int *width)
{
	int	width_;

	width_ = 0;
	while ('0' <= *s && *s <= '9')
	{
		width_ = width_ * 10 + *s - '0';
		++s;
	}
	*width = width_;
	return (s);
}

static void	_finalize_flag(t_flag *flag)
{
	if (ft_is_flag_set(*flag, FLAG_MINUS))
		ft_unset_flag(flag, FLAG_ZERO);
	if (ft_is_flag_set(*flag, FLAG_PLUS))
		ft_unset_flag(flag, FLAG_SPACE);
}

int	load_conversion(const char *s, t_conversion_setting *conversion_setting)
{
	const char	*save_s;

	save_s = s;
	++s;
	ft_memzero(conversion_setting, sizeof(t_conversion_setting));
	s = _load_flags(s, &conversion_setting->flag);
	_finalize_flag(&conversion_setting->flag);
	s = _load_width(s, &conversion_setting->width);
	conversion_setting->conversion_type = *s;
	return (s + 1 - save_s);
}
