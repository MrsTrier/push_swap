/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:37:58 by mcanhand          #+#    #+#             */
/*   Updated: 2020/01/17 13:37:58 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

int			find_place(t_arr **a, int b, t_stack *a_data)
{
	int		place;
	t_arr	*pr;
	int		diff;

	diff = a_data->max - a_data->min;
	pr = *a;
	place = (*a)->content;
	while (pr)
	{
		if ((pr->content > b) && (diff > pr->content - b))
		{
			diff = pr->content - b;
			place = pr->content;
		}
		pr = pr->next;
	}
	return (place);
}

t_cmnd		choose_best(t_arr **a, t_arr **b, t_stack **a_data, t_stack *b_data)
{
	t_arr	*pr;
	t_cmnd	cmnd;
	int		i;
	int		best_place;

	i = 1;
	cmnd.c = 1000000000;
	pr = *b;
	best_place = 0;
	while (pr)
	{
		cmnd.place = find_place(a, pr->content, *a_data);
		if (calculate_comands(a, &cmnd, min_is(i, b_data->length - i),
															(*a_data)->length))
		{
			cmnd.best = pr->content;
			best_place = cmnd.place;
		}
		i++;
		pr = pr->next;
	}
	cmnd.place = best_place;
	(*a_data)->place = cmnd.place;
	(*a_data)->best = cmnd.best;
	return (cmnd);
}

int			sorting(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_cmnd	cmnd;
	int		i;
	int		j;

	while (*b && b_data->length)
	{
		cmnd = choose_best(a, b, &a_data, b_data);
		if ((cmnd.b >= cmnd.a && cmnd.a > 0) ||
			(cmnd.a >= cmnd.b && cmnd.b > 0))
		{
			i = detect_index(a, cmnd.place);
			j = detect_index(b, cmnd.best);
			if (((min_is(i, a_data->length - i)) == i - 1) &&
				(min_is(j, b_data->length - j) == j - 1))
				optimazation_rr(a, b, a_data, b_data);
			else if (((min_is(i, a_data->length - i)) == a_data->length - i + 1)
				&& (min_is(j, b_data->length - j) == b_data->length - j + 1))
				optimazation_rrr(a, b, a_data, b_data);
		}
		switch_in_b(a, b, b_data, cmnd.best);
		merge_comands(b_data, a_data);
		switch_in_a(a, b, a_data, cmnd.place);
		execute_pa(a, b, a_data, b_data);
	}
	return (0);
}
