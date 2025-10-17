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

static const char	*_load_width(const char *s, va_list *ap, t_conversion_setting *conversion_setting)
{
	int	width_;

	if (*s == '*')
	{
		conversion_setting->width = va_arg(*ap, int);
		if (conversion_setting->width < 0)
		{
			conversion_setting->width *= -1;
			conversion_setting->flag |= FLAG_MINUS;
		}
		return (s + 1);
	}
	width_ = 0;
	while ('0' <= *s && *s <= '9')
	{
		width_ = width_ * 10 + *s - '0';
		++s;
	}
	conversion_setting->width = width_;
	return (s);
}

static const char	*_load_precision(const char *s, va_list *ap, t_conversion_setting *conversion_setting)
{
	int	precision_;

	if (*s != '.')
		return (s);
	conversion_setting->flag |= FLAG_DOT;
	++s;
	if (*s == '*')
	{
		conversion_setting->precision = va_arg(*ap, int);
		return (s + 1);
	}
	precision_ = 0;
	while ('0' <= *s && *s <= '9')
	{
		precision_ = precision_ * 10 + *s - '0';
		++s;
	}
	conversion_setting->precision = precision_;
	return (s);
}

static void	_finalize_flag(t_flag *flag)
{
	if (ft_is_flag_set(*flag, FLAG_MINUS))
		ft_unset_flag(flag, FLAG_ZERO);
	if (ft_is_flag_set(*flag, FLAG_PLUS))
		ft_unset_flag(flag, FLAG_SPACE);
}

int	load_conversion_setting(const char *s, va_list *ap, t_conversion_setting *conversion_setting)
{
	const char	*save_s;

	save_s = s;
	++s;
	ft_bzero(conversion_setting, sizeof(t_conversion_setting));
	s = _load_flags(s, &conversion_setting->flag);
	s = _load_width(s, ap, conversion_setting);
	s = _load_precision(s, ap, conversion_setting);
	conversion_setting->conversion_type = *s;
	_finalize_flag(&conversion_setting->flag);
	return (s + 1 - save_s);
}
