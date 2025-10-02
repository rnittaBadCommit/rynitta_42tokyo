#include "get_next_line.h"

void	update_node(t_save_list *save_list, t_save_list_node *node)
{
	char	*tmp;
	int		len;
	int		i_linebreak;

	i_linebreak = calculate_index_c(node->save_data, '\n');
	len = calculate_index_c(node->save_data, '\0');
	if (i_linebreak == NOT_FOUND)
		delete_save_list_node(save_list, node->fd);
	tmp = node->save_data;
	node->save_data = ft_strndup(node->save_data + i_linebreak + 1, len - i_linebreak);
	if (!node->save_data)
		delete_save_list_node(save_list, node->fd);
	free(tmp);
}

t_status	read_process(t_save_list_node *node)
{
	char				buf[(unsigned long long int)BUFFER_SIZE + 1];
	int					ret;
	char				*tmp;

	while (1)
	{
		ret = read(node->fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ERROR);
		if (ret == 0)
			return (READ_FINISHED);
		buf[ret] = '\0';
		tmp = node->save_data;
		node->save_data = ft_strcatdup(node->save_data, buf);
		free(tmp);
		if (calculate_index_c(node->save_data, '\n') != NOT_FOUND)
			return (SUCCESS);
	}
	return (ERROR);
}

char	*case_need_to_read(t_save_list_node *node)
{
	t_status	status;
	char		*ret;

	status = read_process(node);
	if (status == ERROR)
		ret = NULL;
	else if (node->save_data[0] == '\0')
		ret = NULL;
	else
		ret = ft_strndup(node->save_data, \
			calculate_index_c(node->save_data, '\n'));
	return (ret);
}

char	*get_next_line(int fd)
{
	char				*ret;
	static t_save_list	save_list;
	t_save_list_node	*node;
	int					len;

	node = find_or_create_save_list_node(&save_list, fd);
	if (!node)
		return (NULL);
	len = calculate_index_c(node->save_data, '\n');
	if (len != NOT_FOUND)
		ret = ft_strndup(node->save_data, len);
	else
		ret = case_need_to_read(node);
	if (!ret)
		delete_save_list_node(&save_list, fd);
	else
		update_node(&save_list, node);
	return (ret);
}
