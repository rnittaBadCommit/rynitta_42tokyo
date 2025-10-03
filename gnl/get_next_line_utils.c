#include "get_next_line.h"

void	delete_save_list_node(t_save_list *save_list, int fd_to_delete)
{
	t_save_list_node	*node_;
	t_save_list_node	*tmp;

	node_ = save_list->head;
	if (node_->fd == fd_to_delete)
	{
		save_list->head = save_list->head->next;
		free(node_->save_data);
		free(node_);
		return ;
	}
	while (node_->next)
	{
		if (node_->next->fd == fd_to_delete)
		{
			if (save_list->tail->fd == fd_to_delete)
				save_list->tail = node_;
			tmp = node_->next->next;
			free(node_->next->save_data);
			free(node_->next);
			node_->next = tmp;
			return ;
		}
		node_ = node_->next;
	}
}

t_save_list_node	*find_or_create_save_list_node(t_save_list *save_list, int fd_to_find)
{
	t_save_list_node	*node_;

	node_ = save_list->head;
	while (node_)
	{
		if (node_->fd == fd_to_find)
			return (node_);
		node_ = node_->next;
	}
	node_ = (t_save_list_node *)malloc(sizeof(t_save_list_node));
	if (!node_)
		return (NULL);
	node_->fd = fd_to_find;
	node_->next = NULL;
	node_->save_data = ft_strndup("", 0);
	node_->len_data = 0;
	if (!node_->save_data)
	{
		free(node_);
		return (NULL);
	}
	if (!save_list->head)
	{
		save_list->head = node_;
		save_list->tail = node_;
	}
	else
	{
		save_list->tail->next = node_;
		save_list->tail = node_;
	}
	return (node_);
}

int	calculate_index_c(char *s, int len_s, char to_find)
{
	int	ret;

	ret = 0;
	while (ret < len_s)
	{
		if (s[ret] == to_find)
			return (ret);
		++ret;
	}
	return (NOT_FOUND);
}

char	*ft_strndup(char *s, int len)
{
	int		i;
	char	*ret;

	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strcatdup(char *original, int len_original, char *to_append, int len_append)
{
	int		i;
	int		i_ret;
	char	*ret;

	ret = (char *)malloc(len_original + len_append + 1);
	if (!ret)
		return (NULL);
	i_ret = 0;
	i = 0;
	while (i < len_original)
	{
		ret[i_ret] = original[i];
		++i_ret;
		++i;
	}
	i = 0;
	while (i < len_append)
	{
		ret[i_ret] = to_append[i];
		++i_ret;
		++i;
	}
	ret[i_ret] = '\0';
	return (ret);
}
