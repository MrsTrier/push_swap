#include "execute.h"
#include "push_swap.h"

t_list_arr  *nb_lstnew()
{
    t_list_arr *new_list;

    if (!(new_list = (t_list_arr*)malloc(sizeof(t_list_arr))))
        return (NULL);
//    if (!nb)
//        new_list->content = NULL;
//    else
//        new_list->content = nb;
//    new_list->next = NULL;
    return (new_list);
}

t_list_arr	*create_nb_elem(int nb, t_list_arr **lst)
{
	t_list_arr	*tmp_lst;

	if ((*lst)->content)
	{
		if (!(tmp_lst = nb_lstnew()))
			return (-1);
		(*lst)->next = tmp_lst;
		tmp_lst->content = nb;
		*lst = tmp_lst;
	}
	else
		(*lst)->content = nb;
	return (*lst);
}

int		nb_lst_length(t_list_arr *lst)
{
	t_list_arr  *new_item;
	int         count;

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

int		lst_sorted_ac(t_list *lst)
{
	t_list *new_item;

	if (!lst)
		return (0);
	new_item = lst;
	while (new_item->next)
	{
		if ((*(int *)(new_item->content)) > (*(int *)(new_item->next->content)))
			return (0);
		new_item = new_item->next;
	}
	return (1);
}

int		lst_sorted_dec(t_list *lst)
{
	t_list *new_item;

	if (!lst)
		return (0);
	new_item = lst;
	while (new_item->next)
	{
		if (new_item->content < new_item->next->content)
			return (0);
		new_item = new_item->next;
	}
	return (1);
}


void	nb_push_back(t_list_arr **start, t_list_arr *new)
{
	t_list_arr		*lst;

	lst = *start;
	if (!(*start))
		*start = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}


//sa
//pb
//pb
//pb
//rr
//rrr
//sa
//pa


