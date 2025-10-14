#include "ft_printf.h"

bool	is_conversion(const char *s)
{
	// t_flag	flag;

	// ft_memzero(&flag, sizeof(t_flag));
	if (*s != '%' || *(s + 1) == '%')
		return (false);
	
	return (true);
	// while (ft_findc(CONVERSION_CHARACTERS, *s) != -1)
	// 	++s;
	
}
