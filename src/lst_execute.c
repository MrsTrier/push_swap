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

#include "execute.h"

#include "libft.h"

t_arr				*nb_list_at(t_arr *begin_list, unsigned int nbr)
{
	unsigned int	i;

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

int					*lst_to_arr(t_arr *lst, int ac)
{
	t_arr			*new_item;
	int				*arr;
	int				i;

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

void				execute_rb(t_arr **a, t_arr **b, int rr, t_stack *b_data)
{
	t_arr			*head;
	t_arr			*tail;

	if (!rr)
	{
		(*b_data->cmnd) = "rb\n";
		b_data->cmnd++;
	}
	if (!(*b))
		return ;
	head = *b;
	tail = *b;
	(*b) = (*b)->next;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	if ((b_data->flag & VISUALIZE_FLAG) && rr == 0)
		visualize(a, b, RB, b_data);
}

void				execute_ss(t_arr **a, t_arr **b, t_stack *a_data,
		t_stack *b_data)
{
	(*a_data->cmnd) = "ss\n";
	a_data->cmnd++;
	execute_sa(a, b, a_data, 1);
	execute_sb(a, b, b_data, 1);
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, SS, a_data);
}

void				execute_rr(t_arr **a, t_arr **b, t_stack *a_data,
		t_stack *b_data)
{
	(*a_data->cmnd) = "rr\n";
	a_data->cmnd++;
	execute_ra(a, b, 1, a_data);
	execute_rb(a, b, 1, a_data);
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RR, a_data);
}
