/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:43 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:48 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "push_swap.h"

int		execute_sa(t_arr **a, t_arr **b, t_stack *a_data, int ss)
{
	t_arr	*pr_a;
	int		tmp;

	if (!ss)
	{
		(*a_data->cmnd) = "sa\n";
		a_data->cmnd++;
		pr_a = *a;
	}
	if (a_data->length < 2)
		return (0);
	else
	{
		tmp = (nb_list_at(pr_a, 0)->content);
		nb_list_at(pr_a, 0)->content = nb_list_at(pr_a, 1)->content;
		nb_list_at(pr_a, 1)->content = tmp;
	}
	if ((a_data->flag & VISUALIZE_FLAG) && ss == 0)
		visualize(a, b, SA, a_data->flag & COLOR_FLAG ? 1 : 0);
	return (1);
}

int		execute_sb(t_arr **a, t_arr **b, t_stack *b_data, int ss)
{
	t_arr		*pr;
	int			tmp;

	if (!ss)
	{
		(*b_data->cmnd) = "sb\n";
		b_data->cmnd++;
	}
	pr = *b;
	if (b_data->length <= 2)
		return (0);
	else
	{
		tmp = (nb_list_at(pr, 0)->content);
		nb_list_at(pr, 0)->content = nb_list_at(pr, 1)->content;
		nb_list_at(pr, 1)->content = tmp;
	}
	if ((b_data->flag & VISUALIZE_FLAG) && ss == 0)
		visualize(a, b, SB, b_data->flag & COLOR_FLAG ? 1 : 0);
	return (1);
}

void	execute_pa(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_arr *new_item;
	t_arr *new_a;

	(*a_data->cmnd) = "pa\n";
	a_data->cmnd++;
	new_a = *b;
	new_item = nb_lstnew();
	ft_memmove(new_item, new_a, sizeof(new_a));
	new_item->next = *a;
	*a = new_item;
	*b = new_a->next;
//	free_lst_arr(new_a);
	free(new_a);
	a_data->length++;
	b_data->length--;
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, PA, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	execute_pb(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_arr *new_item;
	t_arr *new_a;

	(*a_data->cmnd) = "pb\n";
	a_data->cmnd++;
	new_a = *a;
	new_item = nb_lstnew();
	new_item->content = (*a)->content;
	if (b_data->length != 0)
		new_item->next = *b;
	*b = new_item;
	*a = new_a->next;
	free(new_a);
	b_data->length++;
	a_data->length--;
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, PB, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	execute_ra(t_arr **a, t_arr **b, int rr, t_stack *a_data)
{
	t_arr *head;
	t_arr *tail;

	if (!rr)
	{
		(*a_data->cmnd) = "ra\n";
		a_data->cmnd++;
	}
	if (!(*a))
		return ;
	head = *a;
	tail = *a;
	(*a) = (*a)->next;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
	if ((a_data->flag & VISUALIZE_FLAG) && rr == 0)
		visualize(a, b, RA, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	execute_rb(t_arr **a, t_arr **b, int rr, t_stack *b_data)
{
	t_arr *head;
	t_arr *tail;

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
		visualize(a, b, RB, b_data->flag & COLOR_FLAG ? 1 : 0);
}

void	execute_ss(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	(*a_data->cmnd) = "ss\n";
	a_data->cmnd++;
	execute_sa(a, b, a_data, 1);
	execute_sb(a, b, b_data, 1);
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, SS, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	execute_rr(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	(*a_data->cmnd) = "rr\n";
	a_data->cmnd++;
	execute_ra(a, b, 1, a_data);
	execute_rb(a, b, 1, a_data);
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RR, a_data->flag & COLOR_FLAG ? 1 : 0);
}
