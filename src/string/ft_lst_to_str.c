/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:42:28 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:14:30 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_string_len(t_list *lst)
{
	size_t sum_length;

	sum_length = 0;
	while (lst)
	{
		sum_length += lst->content_size ? lst->content_size - 1 : 0;
		lst = lst->next;
	}
	return (sum_length);
}

char			*ft_lst_to_str(t_list *lst)
{
	char	*res;
	size_t	sum_length;
	size_t	cur;

	sum_length = calc_string_len(lst);
	if (!(res = ft_strnew(sum_length)))
		return (NULL);
	cur = 0;
	while (lst)
	{
		if (lst->content && lst->content_size)
		{
			ft_memcpy(res + cur, lst->content, lst->content_size - 1);
			cur += lst->content_size - 1;
		}
		lst = lst->next;
	}
	res[cur] = '\0';
	return (res);
}
