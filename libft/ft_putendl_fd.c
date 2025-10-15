#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	write(fd, s, ft_strlen(s));
	c = '\n';
	write(fd, &c, 1);
}
