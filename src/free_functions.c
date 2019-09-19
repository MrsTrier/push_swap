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

void	free_arr(int ac, char **arr)
{
	while (ac != -1)
	{
		free(arr[ac]);
		ac--;
	}
}
