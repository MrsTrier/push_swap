/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportive_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:45 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:18 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

int		easy(t_arr **a, t_stack *a_data)
{
	int i;
	int j;

	i = detect_index(a, a_data->min);
	j = detect_index(a, a_data->max);
	if (i - j == 1 || i - j == -2)
		return (0);
	return (1);
}

int		mk_easy_sort(t_arr **a, t_arr **b, t_stack *a_data)
{
	int i;

	i = 0;
	if (easy(a, a_data))
	{
		executeSA(a, b, a_data, 0);
		i++;
	}
	return (i);
}

int		free_a(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	int		i;
	int		j;

	j = a_data->length;
	i = 0;
	while (a_data->length != 3)
	{
		(((*a)->content != a_data->min) && ((*a)->content != a_data->max)
			&& ((*a)->content != a_data->mdn)) ? executePB(a, b, a_data, b_data) :
				executeRA(a, b, 0, a_data);
			i++;
	}
	return (i);
}

int 	min_is(int up, int bottom)
{
	if (up <= bottom + 1)
		return (up - 1);
	else
		return (bottom + 1);
}

int		calculate_comands(t_arr **a, t_cmnd *cmnd, int b, int a_length)
{
	int			i;
	int			trns_to_place;

	i = detect_index(a, cmnd->place);
	trns_to_place = min_is(i, a_length - i);
	if (trns_to_place + b < cmnd->c)
	{
		cmnd->c = trns_to_place + b;
		cmnd->b = b;
		cmnd->a = cmnd->c - cmnd->b;
		return (1);
	}
	return (0);
}
