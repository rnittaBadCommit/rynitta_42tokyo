#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int ret;

	if (!lst)
		return (0);
	ret = 1;
	while (lst->next)
	{
		lst = lst->next;
		++ret;
	}
	return (ret);
}
