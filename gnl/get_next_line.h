#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
	int					fd;
	char				*save_data;
	int					len_data;
	// int					status;
	struct s_save_list_node	*next;
}	t_save_list_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# define NOT_FOUND -1

void	delete_save_list_node(t_save_list_node *save_list, int fd_to_delete);
t_save_list_node	*find_or_create_save_list_node(t_save_list_node *save_list, int fd_to_find);
int	calculate_index_c(char *s, int len_s, char to_find);
char	*ft_strndup(char *s, int len);
char	*ft_strcatdup(char *original, int len_original, char *to_append, int len_append);
char	*get_next_line(int fd);




#endif