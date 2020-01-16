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

//#include "push_swap.h"
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

int				handle_input_in_row(char **av)
{
	char		**result;
	int			num;
	char		*line;

	line = ft_strjoin("0 ", av[1]);
	if ((result = ft_strsplit(line, ' ')) != NULL)
	{
		num = count_wrds(result);
		free_arr(result);
		free(result);
		free(line);
		return (num);
	}
	free(result);
	free(line);
	return (-1);
}
