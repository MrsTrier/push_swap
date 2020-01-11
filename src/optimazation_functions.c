/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimazation_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:57:57 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:23 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

int		switch_in_b(t_arr **a, t_arr **b, t_stack *b_data, int nb)
{
	int c;
	int i;

	c = 0;
	i = detect_index(b, nb);
	while ((*b)->content != nb)
	{
		c++;
		if ((min_is(i, b_data->length - i)) == i - 1)
			execute_rb(a, b, 0, b_data);
		else
			execute_rrb(a, b, b_data, 1);
	}
	return (c);
}

int		switch_in_a(t_arr **a, t_arr **b, t_stack *a_data, int nb)
{
	int c;
	int i;

	c = 0;
	i = detect_index(a, nb);
	while ((*a)->content != nb)
	{
		c++;
		if ((min_is(i, a_data->length - i)) == i - 1)
			execute_ra(a, b, 0, a_data);
		else
			execute_rra(a, b, a_data, 1);
	}
	return (c);
}

int		optimazationRR(t_arr **a, t_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != cmnd.place) && ((*b)->content != cmnd.best))
	{
		execute_rr(a, b, a_data, b_data);
		c++;
	}
	return (c);
}

int		optimazationRRR(t_arr **a, t_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != cmnd.place) && ((*b)->content != cmnd.best))
	{
		execute_rrr(a, a_data, b, b_data);
		c++;
	}
	return (c);
}

int		how_much_sorted(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	int     i;
	int     elem;
	int     pb;

	pb = 0;
	elem = -1;
	i = 0;
	while (a_data->length - i - 1)
	{
		if ((pb = lst_sorted_ac(*a, i, a_data->length)) == 0)
		{
			elem = i;
			break ;
		}
		i++;
	}
	if (!elem)
		return (0);
	if (elem == 1)
		execute_sa(a, b, a_data, 0);
	else if (elem == 2)
	{
		execute_ra(a, b, 0, a_data);
		execute_sa(a, b, a_data, 0);
		execute_rra(a, b, a_data, 1);
		return (1);
	}
	else if ((pb = lst_sorted_ac(*a, i, a_data->length)) > (a_data->length / 2)) // !!!!!
	{
		while (a_data->length - pb)
		{
			execute_rra(a, b, a_data, 1);
			execute_pb(a, b, a_data, b_data);
			pb++;
		}
	}
	i = a_data->length - 1;
	elem = -1;
	while (i != a_data->length - 2)
	{
		if (lst_sorted_ac(*a, 0, i) == 0)
		{
			elem = i;
			break ;
		}
		i--;
	}
	if (elem == a_data->length - 1)
	{
		execute_rra(a, b, a_data, 1);
		execute_rra(a, b, a_data, 1);
		execute_sa(a, b, a_data, 0);
		execute_ra(a, b, 0, a_data);
		execute_ra(a, b, 0, a_data);
	}
	else if (elem == a_data->length - 2)
	{
		execute_rra(a, b, a_data, 1);
		execute_rra(a, b, a_data, 1);
		execute_rra(a, b, a_data, 1);
		execute_sa(a, b, a_data, 0);
		execute_ra(a, b, 0, a_data);
		execute_ra(a, b, 0, a_data);
		execute_ra(a, b, 0, a_data);
	}
	else
		return (0);
	return (1);
}
