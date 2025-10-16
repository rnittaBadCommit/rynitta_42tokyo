/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rynitta <rynitta@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:52:56 by rynitta           #+#    #+#             */
/*   Updated: 2025/10/16 02:53:12 by rynitta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	while (*str == '\f' || *str == '\t' || *str == ' ' \
		|| *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		++str;
	}
	return (sign * ret);
}
