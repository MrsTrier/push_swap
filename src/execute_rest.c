/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:15 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:03:14 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "checker.h"
#include "push_swap.h"

void	execute_rrb(t_arr **a, t_arr **b, t_stack *b_data, int rrr)
{
	t_arr	*tmpl;

	if (rrr)
	{
		(*b_data->cmnd) = (char *)malloc(sizeof(char) * 5);
		(*b_data->cmnd)[0] = 'r';
		(*b_data->cmnd)[1] = 'r';
		(*b_data->cmnd)[2] = 'b';
		(*b_data->cmnd)[3] = '\n';
		(*b_data->cmnd)[4] = '\0';
		b_data->cmnd++;
	}
	tmpl = nb_list_at(*b, b_data->length - 1);
	nb_list_at(*b, b_data->length - 2)->next = NULL;
	tmpl->next = *b;
	*b = tmpl;
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRB, b_data);
}

void	execute_rra(t_arr **a, t_arr **b, t_stack *a_data, int rrr)
{
	t_arr	*tmpl;
	t_arr	*pr;

	if (rrr)
	{
		(*a_data->cmnd) = (char *)malloc(sizeof(char) * 5);
		(*a_data->cmnd)[0] = 'r';
		(*a_data->cmnd)[1] = 'r';
		(*a_data->cmnd)[2] = 'a';
		(*a_data->cmnd)[3] = '\n';
		(*a_data->cmnd)[4] = '\0';
		a_data->cmnd++;
	}
	pr = *a;
	tmpl = nb_list_at(pr, a_data->length - 1);
	nb_list_at(*a, a_data->length - 2)->next = NULL;
	tmpl->next = *a;
	*a = tmpl;
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRA, a_data);
}

void	execute_rrr(t_arr **a, t_stack *a_data, t_arr **b, t_stack *b_data)
{
	(*a_data->cmnd) = (char *)malloc(sizeof(char) * 5);
	(*a_data->cmnd)[0] = 'r';
	(*a_data->cmnd)[1] = 'r';
	(*a_data->cmnd)[2] = 'r';
	(*a_data->cmnd)[3] = '\n';
	(*a_data->cmnd)[4] = '\0';
	a_data->cmnd++;
	execute_rra(a, b, a_data, 0);
	execute_rrb(a, b, b_data, 0);
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRR, a_data);
}
