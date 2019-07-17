#include "execute.h"

void	lst_delete_last(t_list **start)
{
	t_list		*lst;

	lst = *start;
	if (!(*start))
		return ;
	else
	{
		while (lst->next)
			lst = lst->next;
		free(lst);
	}
}

int		create_elem(void *str, size_t len, t_list **lst)
{
	t_list	*tmp_lst;

	if ((*lst)->content != NULL)
	{
		if (!(tmp_lst = ft_lstnew(str, len)))
			return (-1);
		(*lst)->next = tmp_lst;
		*lst = tmp_lst;
	}
	else
	{
		(*lst)->content = str;
		(*lst)->content_size = len;
		(*lst)->next = NULL;
	}
	return (1);
}

int		lst_length(t_list *lst)
{
	t_list	*new_item;
	int 	count;

	count = 0;
	if (!lst)
		return (0);
	new_item = lst;
	while (new_item)
	{
		new_item = new_item->next;
		count++;
	}
	free(new_item);
	return (count);
}

int		lst_sorted(t_list *lst)
{
	t_list *new_item;

	if (!lst)
		return (0);
	new_item = lst;
	while (new_item->next)
	{
		if (ft_atoi(new_item->content) < ft_atoi(new_item->next->content))
			return (0);
		new_item = new_item->next;
	}
	return (1);
}


//sa
//pb
//pb
//pb
//rr
//rrr
//sa
//pa


