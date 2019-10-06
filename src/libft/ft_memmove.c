/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:48:40 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/17 19:25:42 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memmove(void *dst, const void *src, size_t len)
{
    size_t				i;
    unsigned char		*ptr;
    const unsigned char	*ptr2;

    ptr = (unsigned char*)dst;
    ptr2 = (unsigned char*)src;
    i = 0;
    if (ptr2 < ptr)
        while (++i <= len)
            ptr[len - i] = ptr2[len - i];
    else
        while (len-- > 0)
            *(ptr++) = *(ptr2++);
    return (dst);
}

//void	*ft_memmove(void *dst, const void *src, size_t len)
//{
//	unsigned char	*s1;
//	unsigned char	*s2;
//
//	s1 = (unsigned char *)dst;
//	s2 = (unsigned char *)src;
//	if (s2 < s1)
//	{
//		s1 = (unsigned char *)s1 + len - 1;
//		s2 = (unsigned char *)s2 + len - 1;
//		while (len)
//		{
//			*s1-- = *s2--;
//			len--;
//		}
//	}
//	else
//	{
//		while (len)
//		{
//			*s1++ = *s2++;
//			len--;
//		}
//	}
//	return ((void *)dst);
//}
