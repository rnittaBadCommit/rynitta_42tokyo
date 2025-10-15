
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!f)
		return (lst);
	if (!lst)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	new_node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_node->next = ft_lstnew((*f)(lst->content));
		if (!new_node->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_lst);
}
