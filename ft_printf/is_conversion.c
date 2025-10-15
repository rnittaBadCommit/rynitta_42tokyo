#include "ft_printf.h"

inline bool	is_conversion(const char *s)
{
	if (*s != '%')
		return (false);
	return (true);
}
