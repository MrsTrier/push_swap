/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:49 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:02:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		detect_index(t_arr **a, int place)
{
	t_arr	*pr;
	int			i;

	pr = *a;
	i = 1;
	while (pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	return (i);
}

void		free_lst_arr(t_arr *lst)
{
    t_arr	*tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
    free(lst);
}


