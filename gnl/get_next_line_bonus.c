/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:54:09 by rynitta           #+#    #+#             */
/*   Updated: 2025/11/14 00:52:34 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	update_node(t_save_list_node *save_list, t_save_list_node *node)
{
	char	*tmp;
	int		i_linebreak;

	i_linebreak = calculate_index_c(node->save_data, node->len_data, '\n');
	if (i_linebreak == NOT_FOUND)
	{
		delete_save_list_node(save_list, node->fd);
		return ;
	}
	tmp = node->save_data;
	node->save_data = ft_strndup(node->save_data + i_linebreak + 1, \
		node->len_data - i_linebreak - 1);
	if (!node->save_data)
	{
		delete_save_list_node(save_list, node->fd);
		free(tmp);
		return ;
	}
	node->len_data -= i_linebreak + 1;
	free(tmp);
}

t_status	read_process(t_save_list_node *node, char *buf)
{
	int					ret;
	char				*tmp;

	while (1)
	{
		ret = read(node->fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ERROR);
		if (ret == 0)
			return (READ_FINISHED);
		tmp = node->save_data;
		node->save_data = \
			ft_strcatdup(node->save_data, node->len_data, buf, ret);
		free(tmp);
		if (!node->save_data)
			return (ERROR);
		node->len_data += ret;
		if (calculate_index_c(buf, ret, '\n') != NOT_FOUND)
			return (SUCCESS);
	}
	return (ERROR);
}

char	*case_need_to_read(t_save_list_node *node)
{
	t_status	status;
	char		*ret;
	int			i_linebreak;
	char		*buf;

	buf = (char *)malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	status = read_process(node, buf);
	free(buf);
	if (status == ERROR)
		ret = NULL;
	else if (node->len_data == 0)
		ret = NULL;
	else
	{
		i_linebreak = calculate_index_c(node->save_data, node->len_data, '\n');
		if (i_linebreak == NOT_FOUND)
			ret = ft_strndup(node->save_data, node->len_data);
		else
			ret = ft_strndup(node->save_data, i_linebreak + 1);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char					*ret;
	static t_save_list_node	save_list;
	t_save_list_node		*node;
	int						len;

	node = find_or_create_save_list_node(&save_list, fd);
	if (!node)
		return (NULL);
	len = calculate_index_c(node->save_data, node->len_data, '\n');
	if (len != NOT_FOUND)
		ret = ft_strndup(node->save_data, len + 1);
	else
		ret = case_need_to_read(node);
	if (!ret)
		delete_save_list_node(&save_list, fd);
	else
		update_node(&save_list, node);
	return (ret);
}
