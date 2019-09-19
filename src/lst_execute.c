/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:38 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:35 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arr	*nb_list_at(t_arr *begin_list, unsigned int nbr)
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

int     *lst_to_arr(t_arr *lst, int ac)
{
	t_arr  *new_item;
	int     *arr;
	int     i;

	if (!lst)
		return (NULL);
	i = 0;
	new_item = lst;
	arr = (int *)malloc(sizeof(int) * ac);
	while (new_item->next)
	{
		arr[i] = new_item->content;
		new_item = new_item->next;
		i++;
	}
	arr[i] = new_item->content;
	return (arr);
}