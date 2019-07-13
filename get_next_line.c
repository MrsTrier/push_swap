/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:55:03 by galiza            #+#    #+#             */
/*   Updated: 2019/05/21 14:30:43 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		iteration(char **str, char **line, const int fd)
{
	char	*tmp;
	int		len;

	if (ft_strchr(str[fd], '\n'))
	{
		len = ft_strlen(str[fd]) - (ft_strchr(str[fd], '\n') - str[fd]);
		tmp = ft_strnew(len + 1);
		ft_strncpy(tmp, ft_strchr(str[fd], '\n') + 1, len - 1);
		*line = ft_strsub(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd]);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][0])
	{
		if (!(ft_strchr(str[fd], '\n')))
			return (-1);
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else
		return (0);
	return (1);
}

void	copy(char **str, char *buf, int fd)
{
	char	*tmp;
	int		strlen;
	int		buflen;

	if (!str[fd])
		str[fd] = ft_strnew(1);
	strlen = ft_strlen(str[fd]);
	buflen = ft_strlen(buf);
	tmp = ft_strnew(strlen + buflen + 1);
	ft_strncpy(tmp, str[fd], strlen);
	ft_strncpy(tmp + strlen, buf, buflen);
	free(str[fd]);
	str[fd] = tmp;
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[12000];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		copy(str, buf, fd);
		if (BUFF_SIZE == 1)
		{
			if (buf[ret - 1] == '\n')
				break ;
		}
		else if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (!ret && !str[fd])
		return (0);
	return (iteration(str, line, fd));
}
