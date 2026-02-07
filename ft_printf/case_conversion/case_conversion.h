/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_conversion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:46:59 by rynitta           #+#    #+#             */
/*   Updated: 2026/02/07 10:51:27 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASE_CONVERSION_H
# define CASE_CONVERSION_H

typedef struct s_conversion_setting
{
	t_flag	flag;
	int		width;
	int		precision;
	char	conversion_type;
}	t_conversion_setting;

int	case_s(char *s, t_conversion_setting *conversion_setting);
int	case_di(long long int n, t_conversion_setting *conversion_setting);
int	case_c(char c, t_conversion_setting *conversion_setting);
int	case_p(void *p, t_conversion_setting *conversion_setting);
int	case_u(unsigned long long int n, t_conversion_setting *conversion_setting);
int	case_xx(unsigned long long int n, t_conversion_setting *conversion_setting);
int	load_conversion_setting(const char *s, va_list *ap, \
	t_conversion_setting *conversion_setting);
int	calculate_len_numbers(long long int n, \
	t_conversion_setting *conversion_setting);
int	calculate_len_numbers_unsigned(unsigned long long int n, \
	t_conversion_setting *conversion_setting);

#endif
