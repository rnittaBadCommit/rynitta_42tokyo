#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last_list;

	if (*lst)
	{
		last_list = ft_lstlast(*lst);
		last_list->next = new;
	}
	else
		*lst = new;
}
