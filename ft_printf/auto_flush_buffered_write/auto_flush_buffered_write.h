#ifndef AUTO_FLUSH_BUFFERED_WRITE_H
# define AUTO_FLUSH_BUFFERED_WRITE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef enum e_mode_buffered_write
{
	NORMAL_WRITE,
	EXPLICIT_FLUSH,
}	t_mode_buffered_write;

int	auto_flush_buffered_write(char *s);
int	flush_buffer(void);


#endif