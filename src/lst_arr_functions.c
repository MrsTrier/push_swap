/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_arr_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:27 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:31 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "push_swap.h"

t_arr  *nb_lstnew()
{
    t_arr *new_list;

    if (!(new_list = (t_arr*)malloc(sizeof(t_arr))))
        return (NULL);
    new_list->next = NULL;
    return (new_list);
}

t_arr	*create_nb_elem(int nb, t_arr **lst, int i)
{
	t_arr	*tmp_lst;

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

int		lst_sorted_ac(t_arr *lst, int elem, int l_elem) {
    t_arr *new_item;
    int i;

    i = 0;
    if (!lst)
        return (0);
    new_item = lst;
    while (new_item->next && i != elem) {
        new_item = new_item->next;
        i++;
    }
    i = 0;
    while (i != l_elem - elem - 1) {
        i += 1;
        if (new_item->content > new_item->next->content)
            return (i);
        new_item = new_item->next;

    }
    return (0);
}

void	nb_push_back(t_arr **start, int nb)
{
	t_arr		*lst;
	t_arr		*new;

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
