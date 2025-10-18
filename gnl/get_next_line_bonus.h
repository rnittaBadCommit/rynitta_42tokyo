/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:54:35 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/18 13:57:56 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_status
{
	ERROR,
	SUCCESS,
	READ_FINISHED,
}	t_status;

typedef struct s_save_list_node
{
	int						fd;
	char					*save_data;
	int						len_data;
	struct s_save_list_node	*next;
}	t_save_list_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# define NOT_FOUND -1

void				delete_save_list_node( \
	t_save_list_node *save_list, int fd_to_delete);
t_save_list_node	*find_or_create_save_list_node( \
	t_save_list_node *save_list, int fd_to_find);
int					calculate_index_c(char *s, int len_s, char to_find);
char				*ft_strndup(char *s, int len);
char				*ft_strcatdup(char *original, int len_original, \
	char *to_append, int len_append);
char				*get_next_line(int fd);

#endif
