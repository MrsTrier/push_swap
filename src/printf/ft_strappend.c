/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:10:26 by jleann            #+#    #+#             */
/*   Updated: 2019/06/04 15:54:53 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*res;

	if (!*s1 || !*s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = ft_strnew(l1 + l2);
	ft_memcpy(res, s1, l1);
	ft_memcpy(s1 + l1, s2, l2);
	return (res);
}
