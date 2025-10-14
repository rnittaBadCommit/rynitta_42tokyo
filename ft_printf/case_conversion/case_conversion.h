#ifndef CASE_CONVERSION_H
# define CASE_CONVERSION_H

int	case_s(char *s, t_conversion_setting *conversion_setting);
int	case_di(int n, t_conversion_setting *conversion_setting);
int	case_c(char c, t_conversion_setting *conversion_setting);
int	case_p(void *p, t_conversion_setting *conversion_setting);
int	case_u(long long int n, t_conversion_setting *conversion_setting);;
int	case_xX(long long int n, t_conversion_setting *conversion_setting);
int	print_n_c(char c, int len);


#endif