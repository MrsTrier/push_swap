/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:54:11 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 19:56:18 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr)
{
	while (*arr != NULL)
	{
		free(*arr);
		(arr)++;
	}
}

void	let_me_free(t_arr **res_lst, t_stack *a_stack, t_stack *b_stack)
{
	free_arr(a_stack->pr);
	free(a_stack->pr);
	free_arr(b_stack->first_elem);
	free(b_stack->first_elem);
	free_lst_arr(*res_lst);
}

int		count_wrds(char **sp_line)
{
	int	wrds;

	wrds = 1;
	while (sp_line[wrds] != NULL)
		wrds++;
	return (wrds);
}
