/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_flush_buffered_write.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:54:06 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 11:54:54 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	__write_buf(const char *buf, int len_buf, const char *s, int len_s)
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

static int	_auto_flush_buffered_write(const char *s, int len_s, \
	t_mode_buffered_write mode)
{
	static char	buf[BUFFER_SIZE];
	static int	i_buf_end;
	int			ret;

	if (mode == EXPLICIT_FLUSH)
	{
		ret = write(1, buf, i_buf_end);
		i_buf_end = 0;
		return (ret);
	}
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

int	auto_flush_buffered_putstr(const char *s)
{
	int		ret;
	char	*tmp;

	tmp = ft_strrchr(s, '\n');
	if (!tmp)
		return (_auto_flush_buffered_write(s, ft_strlen(s), NORMAL_WRITE));
	ret = _auto_flush_buffered_write(s, tmp - s + 1, NORMAL_WRITE);
	ret += flush_buffer();
	ret += _auto_flush_buffered_write(tmp + 1, \
		ft_strlen(s) - (tmp - s + 1), NORMAL_WRITE);
	return (ret);
}

int	auto_flush_buffered_write(const void *p, size_t size)
{
	int		ret;
	void	*tmp;

	tmp = ft_memrchr(p, '\n', size);
	if (!tmp)
		return (_auto_flush_buffered_write(p, size, NORMAL_WRITE));
	ret = _auto_flush_buffered_write(p, tmp - p + 1, NORMAL_WRITE);
	ret += flush_buffer();
	ret += _auto_flush_buffered_write(tmp + 1, \
		size - (tmp - p + 1), NORMAL_WRITE);
	return (ret);
}

int	flush_buffer(void)
{
	return (_auto_flush_buffered_write(NULL, 0, EXPLICIT_FLUSH));
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int	i;

// 	if (argc > 1)
// 	{
// 		i = 1;
// 		while (argv[i])
// 		{
// 			printf("i: %d\n", i);
// 			auto_flush_buffered_putstr(argv[i]);
// 			printf("\n");
// 			++i;
// 		}
// 		printf("explicit flush\n");
// 		flush_buffer();
// 		printf("\n");
// 		return (0);
// 	}
// 	else
// 	{
// 		auto_flush_buffered_putstr("1");
// 		printf("\n");
// 		auto_flush_buffered_putstr("2");
// 		printf("\n");
// 		auto_flush_buffered_putstr("3");
// 		printf("\n");
// 		auto_flush_buffered_putstr("4");
// 		printf("\n");
// 		auto_flush_buffered_putstr("5");
// 		printf("\n");
// 		auto_flush_buffered_putstr("67");
// 		printf("\n");
// 		auto_flush_buffered_putstr("abcd");
// 		printf("\n");
// 	}
// }
