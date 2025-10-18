#ifndef CASE_CONVERSION_H
# define CASE_CONVERSION_H

int	case_s(char *s, t_conversion_setting *conversion_setting);
int	case_di(int n, t_conversion_setting *conversion_setting);
int	case_c(char c, t_conversion_setting *conversion_setting);
int	case_p(void *p, t_conversion_setting *conversion_setting);
int	case_u(unsigned int n, t_conversion_setting *conversion_setting);
int	case_xX(unsigned long long int n, t_conversion_setting *conversion_setting);
int	load_conversion_setting(const char *s, va_list *ap, t_conversion_setting *conversion_setting);
int	calculate_len_numbers(long long int n, t_conversion_setting *conversion_setting);
int	calculate_len_numbers_unsigned(unsigned long long int n, t_conversion_setting *conversion_setting);

#endif