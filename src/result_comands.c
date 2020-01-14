/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_comands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:46:09 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 19:56:57 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

void	merge_comands(t_stack *b_data, t_stack *a_data)
{
    while (*b_data->pr != NULL)
	{
		(*a_data->cmnd) = *(b_data->cmnd - 1);
		a_data->cmnd++;
		b_data->pr++;
	}
}


