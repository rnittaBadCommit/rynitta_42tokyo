#ifndef AUTO_FLUSH_BUFFERED_WRITE_H
# define AUTO_FLUSH_BUFFERED_WRITE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1027
# endif

typedef enum e_mode_buffered_write
{
	NORMAL_WRITE,
	EXPLICIT_FLUSH,
}	t_mode_buffered_write;

int auto_flush_buffered_write(void *p, size_t size);
int	auto_flush_buffered_putstr(char *s);
int	flush_buffer(void);
int	print_n_c(char c, int len);

#endif