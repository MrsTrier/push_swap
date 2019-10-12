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
        (*arr)++;
	}
	free(arr);
}

//void	free_int_arr(int **arr, int ac)
//{
//    while (ac)
//    {
//        free(*arr);
//        (*arr)++;
//        ac--;
//    }
//    free(arr);
//}
