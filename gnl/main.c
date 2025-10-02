#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*ret;
	int		i;

	if (argc == 1)
	{
		while (1)
		{
			ret = get_next_line(0);
			if (!ret)
				return (0);
			printf("%s\n", ret);
		}
	}
	while (*(++argv))
	{
		// printf("\n\n%s\n\n", argv[0]);
		fd = open(argv[0], O_RDONLY);
		if (fd < 0)
			printf("open fail\n");
		i = 0;
		while (1)
		{
			if (i == 20)
				i = i;
			ret = get_next_line(fd);
			if (!ret)
				break;
			write(1, "\n", 1);
			++i;
		}
	}
}