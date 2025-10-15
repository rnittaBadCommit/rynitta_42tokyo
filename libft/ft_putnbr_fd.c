#include "libft.h"

static void	_ft_putnbr_fd(long long int lln, int fd)
{
	if (lln > 9)
		_ft_putnbr_fd(lln / 10, fd);
	ft_putchar_fd('0' + lln % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int lln;

	lln = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		lln *= -1;
	}
	_ft_putnbr_fd(lln, fd);
}
