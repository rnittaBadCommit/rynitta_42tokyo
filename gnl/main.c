#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int		fd;
	char	*ret;
	int		i;

	++argv;
	if (argc == 1)
		fd = 0;
	else
	{
		printf("%s\n\n", argv[0]);
		fd = open(argv[0], O_RDONLY);
	}
	if (fd < 0)
		printf("open fail\n");
	while (1)
	{
		ret = get_next_line(fd);
		if (!ret)
			break;
		printf("%s\n", ret);
	}
}
