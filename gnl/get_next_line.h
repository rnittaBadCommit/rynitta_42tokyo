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
	// int					status;
	struct s_save_list_node	*next;
}	t_save_list_node;

typedef struct s_save_list
{
	t_save_list_node	*head;
	t_save_list_node	*tail;
}	t_save_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define NOT_FOUND -1

t_save_list_node	*find_or_create_save_list_node(t_save_list *save_list, int fd_to_find);
char				*ft_strndup(char *s, int len);
int					calculate_index_c(char *s, char to_find);
void				delete_save_list_node(t_save_list *save_list, int fd_to_delete);
char				*ft_strcatdup(char *original, char *to_append);
char				*get_next_line(int fd);

#endif