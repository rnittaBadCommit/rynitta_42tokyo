/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:54:20 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:59:15 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*__free_all_substr(char **str_ary, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(str_ary[i]);
		++i;
	}
	return (NULL);
}

static int	_calculate_num_substr(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++ret;
		++s;
	}
	return (ret);
}

static char	*__create_substr(const char *s, char *next_sep_pos)
{
	if (!next_sep_pos)
		return (ft_strdup(s));
	else
		return (ft_substr(s, 0, next_sep_pos - s));
}

static t_status	_fill_str_ary(char **str_ary, const char *s, \
	char sep, size_t num_substr)
{
	size_t	i;
	char	*next_sep_pos;

	i = 0;
	while (i < num_substr)
	{
		if (*s == sep)
			++s;
		else
		{
			next_sep_pos = ft_strchr(s, sep);
			str_ary[i] = __create_substr(s, next_sep_pos);
			if (!str_ary[i])
			{
				__free_all_substr(str_ary, i);
				return (ERROR);
			}
			s = next_sep_pos + 1;
			++i;
		}
	}
	str_ary[i] = NULL;
	return (SUCCESS);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		num_substr;
	t_status	status;

	num_substr = _calculate_num_substr(s, c);
	ret = (char **)malloc(sizeof(char *) * (num_substr + 1));
	if (!ret)
		return (NULL);
	status = _fill_str_ary(ret, s, c, num_substr);
	if (status == ERROR)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
