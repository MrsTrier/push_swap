/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:10:26 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 19:43:13 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *mem, size_t old_size, size_t new_size)
{
	void	*res;

	res = malloc(new_size);
	ft_memcpy(res, mem, old_size);
	free(mem);
	return (res);
}
