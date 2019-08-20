#include "execute.h"
#include "push_swap.h"

t_list_arr	*ft_list_elem(t_list_arr *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (!(begin_list))
		return (NULL);
	while (i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	if (i == nbr)
		return (begin_list);
	return (NULL);
}

t_list_arr  *nb_lstnew()
{
    t_list_arr *new_list;

    if (!(new_list = (t_list_arr*)malloc(sizeof(t_list_arr))))
        return (NULL);
//    if (!nb)
//        new_list->content = NULL;
//    else
//        new_list->content = nb;
    new_list->next = NULL;
    return (new_list);
}

t_list_arr	*create_nb_elem(int nb, t_list_arr **lst, int i)
{
	t_list_arr	*tmp_lst;

	if (i != 1)
	{
		if (!(tmp_lst = nb_lstnew()))
			return (NULL);
		(*lst)->next = tmp_lst;
		tmp_lst->content = nb;
		*lst = tmp_lst;
	}
	else
		(*lst)->content = nb;
	return (*lst);
}

int		lst_sorted_ac(t_list_arr *lst)
{
	t_list_arr *new_item;

	if (!lst)
		return (0);
	new_item = lst;
	while (new_item->next)
	{
		if (new_item->content > new_item->next->content)
			return (0);
		new_item = new_item->next;
	}
	return (1);
}

int		lst_sorted_dec(t_list_arr *lst)
{
	t_list_arr *new_item;

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


void	nb_push_back(t_list_arr **start, int nb)
{
	t_list_arr		*lst;
	t_list_arr		*new;

	lst = *start;
	if (!(*start))
	{
		new = nb_lstnew();
		new->content = nb;
		lst->next = new;
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		new = nb_lstnew();
		new->content = nb;
		lst->next = new;
	}
}
