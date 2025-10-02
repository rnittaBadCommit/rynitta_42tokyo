#include "get_next_line.h"

void	delete_save_list_node(t_save_list *save_list, int fd_to_delete)
{
	t_save_list_node	*node_;
	t_save_list_node	*tmp;

	node_ = save_list->head;
	// if (!node_)
	// 	return;
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
		save_list->tail->next = node_;
	return (node_);
}

int	calculate_index_c(char *s, char to_find)
{
	int	ret;

	ret = 0;
	while (s[ret])
	{
		if (s[ret] == to_find)
			return (ret);
		++ret;
	}
	if (to_find == '\0')
		return (ret);
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

char	*ft_strcatdup(char *original, char *to_append)
{
	int	len_ret_str;
	int	i;
	char	*ret;

	ret = (char *)malloc(calculate_index_c(original, '\0') \
		+ calculate_index_c(to_append, '\0') + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*original)
	{
		ret[i] = *original;
		++original;
		++i;
	}
	while (*to_append)
	{
		ret[i] = *to_append;
		++to_append;
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
