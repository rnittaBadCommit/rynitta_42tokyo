#include "libft.h"

int	ft_putnbr(int n)
{
	long long int	lln;
	char			buf[11];
	int				i;
	
	lln = n;
	if (n < 0)
		lln *= -1;
	buf[10] = '0' + lln % 10;
	i = 9;
	while (lln >= 10)
	{
		lln /= 10;
		buf[i] = '0' + lln % 10;
		--i;
	}
	if (n < 0)
	{
		buf[i] = '-';
		--i;
	}
	return (write(1, buf + i + 1, 10 - i));
}

int	ft_putnbr_base(int n, char *base)
{
	long long int	lln;
	char			buf[33];
	int				i;
	int				len_base;
	
	len_base = ft_strlen(base);
	lln = n;
	if (n < 0)
		lln *= -1;
	buf[32] = base[lln % len_base];
	i = 31;
	while (lln >= len_base)
	{
		lln /= len_base;
		buf[i] = base[lln % len_base];
		--i;
	}
	if (n < 0)
	{
		buf[i] = '-';
		--i;
	}
	return (write(1, buf + i + 1, 32 - i));
}
