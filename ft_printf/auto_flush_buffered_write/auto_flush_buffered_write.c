#include "../ft_printf.h"
#include <stdio.h>

static int	__write_buf(char *buf, int len_buf, char *s, int len_s)
{
	int	ret1;
	int	ret2;

	ret1 = write(1, buf, len_buf);
	if (ret1 == -1)
		return (-1);
	ret2 = write(1, s, len_s);
	if (ret2 == -1)
		return (-1);
	return (ret1 + ret2);
}

static int	_auto_flush_buffered_write(char *s, t_mode_buffered_write mode)
{
	static char	buf[BUFFER_SIZE];
	static int	i_buf_end;
	int			len_s;
	int			ret;

	if (mode == EXPLICIT_FLUSH)
	{
		ret = write(1, buf, i_buf_end);
		i_buf_end = 0;
		return (ret);
	}
	len_s = ft_strlen(s);
	if (i_buf_end + len_s > BUFFER_SIZE)
	{
		ret = __write_buf(buf, i_buf_end, s, len_s);
		i_buf_end = 0;
		return (ret);
	}
	else
	{
		ft_memcpy(buf + i_buf_end, s, len_s);
		i_buf_end += len_s;
		return (0);
	}
}

int	auto_flush_buffered_write(char *s)
{
	return (_auto_flush_buffered_write(s, NORMAL_WRITE));
}

int	flush_buffer(void)
{
	return (_auto_flush_buffered_write(NULL, EXPLICIT_FLUSH));
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int	i;
	
	if (argc > 1)
	{
		i = 1;
		while (argv[i])
		{
			printf("i: %d\n", i);
			auto_flush_buffered_write(argv[i]);
			printf("\n");
			++i;
		}
		printf("explicit flush\n");
		flush_buffer();
		printf("\n");
		return (0);
	}
	else
	{
		auto_flush_buffered_write("1");
		printf("\n");
		auto_flush_buffered_write("2");
		printf("\n");
		auto_flush_buffered_write("3");
		printf("\n");
		auto_flush_buffered_write("4");
		printf("\n");
		auto_flush_buffered_write("5");
		printf("\n");
		auto_flush_buffered_write("67");
		printf("\n");
		auto_flush_buffered_write("abcd");
		printf("\n");
	}
}
