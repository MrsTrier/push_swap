/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:20:50 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 17:24:45 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		create_node(void *str, size_t len, t_list **lst)
{
	t_list	*tmp_lst;

	if (!(tmp_lst = ft_lstnew(str, len)))
		return (-1);
	(*lst)->next = tmp_lst;
	*lst = tmp_lst;
	return (1);
}
