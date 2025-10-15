#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// #       A `#' character specifying that the value should be printed in an ``alternate form''.  For b, c, d, s and u formats, this option
// 		has no effect.  For the o formats the precision of the number is increased to force the first character of the output string to
// 		a zero.  For the x (X) format, a non-zero result has the string 0x (0X) prepended to it.  For a, A, e, E, f, F, g and G formats,
// 		the result will always contain a decimal point, even if no digits follow the point (normally, a decimal point only appears in
// 		the results of those formats if a digit follows the decimal point).  For g and G formats, trailing zeros are not removed from
// 		the result as they would otherwise be;


# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>

# include "../libft/ft_libft.h"

typedef struct s_conversion_setting
{
	t_flag	flag;
	int		width;
	char	conversion_type;
}	t_conversion_setting;


# include "auto_flush_buffered_write/auto_flush_buffered_write.h"
# include "case_conversion/case_conversion.h"

# define CONVERSION_CHARACTERS "cspdiuxX"
# define FLAG_CHARACTERS "-0# +"

# define FLAG_MINUS	(1 << 0)
# define FLAG_ZERO (1 << 1)
# define FLAG_SHARP (1 << 2)
# define FLAG_SPACE (1 << 3)
# define FLAG_PLUS (1 << 4)


int	ft_printf(const char *format, ...);

int	auto_flush_buffered_write(char *s);
int	load_conversion_setting(const char *s, va_list *ap, t_conversion_setting *conversion_setting);
bool	is_conversion(const char *s);


#endif
