/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_flush_buffered_write.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:47:36 by rynitta           #+#    #+#             */
/*   Updated: 2026/02/07 10:47:55 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	auto_flush_buffered_write(const void *p, size_t size);
int	auto_flush_buffered_putstr(const char *s);
int	flush_buffer(void);
int	print_n_c(char c, int len);

#endif