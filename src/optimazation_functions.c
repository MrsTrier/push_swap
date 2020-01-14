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

int		optimazation_rr(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != a_data->place) && ((*b)->content != a_data->best))
	{
		execute_rr(a, b, a_data, b_data);
		c++;
	}
	return (c);
}

int		optimazation_rrr(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != a_data->place) && ((*b)->content != a_data->best))
	{
		execute_rrr(a, a_data, b, b_data);
		c++;
	}
	return (c);
}
