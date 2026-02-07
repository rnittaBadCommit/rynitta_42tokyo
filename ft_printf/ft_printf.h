/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:43:01 by rynitta           #+#    #+#             */
/*   Updated: 2026/02/07 11:17:08 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>

# include "./libft/libft.h"
# include "case_conversion/case_conversion.h"

# define CONVERSION_CHARACTERS "cspdiuxX%%"
# define FLAG_CHARACTERS "-0# +"

# define FLAG_MINUS 1	// (1 << 0)
# define FLAG_ZERO 2	// (1 << 1)
# define FLAG_SHARP 4	// (1 << 2)
# define FLAG_SPACE 8	// (1 << 3)
# define FLAG_PLUS 16	// (1 << 4)
# define FLAG_DOT 32	// (1 << 5)

int		ft_printf(const char *format, ...) \
	__attribute__ ((format(printf, 1, 2)));

int		load_conversion_setting(const char *s, va_list *ap, \
	t_conversion_setting *conversion_setting);
bool	is_conversion(const char *s);

#endif
