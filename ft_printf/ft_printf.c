#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	ret;
	va_list	ap;
	int	i_str;
	t_conversion_setting	conversion_setting;

	va_start(ap, str);
	ret = 0;
	i_str = 0;
	while (str[i_str])
	{
		if (is_conversion(str + i_str))
		{
			i_str += load_conversion(str + i_str, &conversion_setting);
			if (conversion_setting.conversion_type == 'c')
				ret += case_c(va_arg(ap, int), &conversion_setting);
			else if (conversion_setting.conversion_type == 's')
				ret += case_s(va_arg(ap, char *), &conversion_setting);
			else if (conversion_setting.conversion_type == 'd')
				ret += case_di(va_arg(ap, int), &conversion_setting);
			else if (conversion_setting.conversion_type == 'p')
				ret += case_p(va_arg(ap, void *), &conversion_setting);
			else if (conversion_setting.conversion_type == 'u')
				ret += case_u(va_arg(ap, unsigned int), &conversion_setting);
			else if (conversion_setting.conversion_type == 'x')
				ret += case_xX(va_arg(ap, unsigned int), &conversion_setting);
			else if (conversion_setting.conversion_type == 'X')
				ret += case_xX(va_arg(ap, unsigned int), &conversion_setting);
			else
				;
		}
		else
		{
			print_n_c(str[i_str], 1);
			++i_str;
		}
	}
	ret += flush_buffer();
	va_end(ap);
	return (ret);
}

#include <stdio.h>
int main()
{
	setvbuf(stdout, 0, _IONBF, 0);
  ft_printf("1[%10c]\n", 'a');
  ft_printf("2[%-10c]\n", 'a');

  ft_printf("3[%u]\n", 42);
  ft_printf("4[%010u]\n", 42);


  int *p = (void *)10;
  ft_printf("5[%10p]\n", p);

  ft_printf("\n");
  ft_printf("6[%-10p]\n", p);


  ft_printf("\n");
  ft_printf("\n");  
  ft_printf("7[%10p]\n", NULL);

  ft_printf("\n");
  ft_printf("8[%-10p]\n", NULL);

  

  ft_printf("9[%10x]\n", 42);
  ft_printf("10[%010x]\n", 42);

  ft_printf("\n");
  ft_printf("11[%-10x]\n", 42);

  
  ft_printf("12[% d]\n", 42);
  ft_printf("13[%10d]\n", 42);
  ft_printf("14[%010d]\n", 42);
  ft_printf("15[% 10d]\n", 42);

  ft_printf("\n");
  ft_printf("16[%-10d]\n", 42);
  ft_printf("17[%- 10d]\n", 42);

  ft_printf("\n");
  ft_printf("\n");
  ft_printf("18[% d]\n", -42);
  ft_printf("19[%10d]\n", -42);
  ft_printf("20[%010d]\n", -42);
  ft_printf("21[% 10d]\n", -42);

  ft_printf("\n");
  ft_printf("22[%-10d]\n", -42);
  ft_printf("23[%- 10d]\n", -42);
}
