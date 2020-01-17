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

#include "execute.h"

void			merge_comands(t_stack *b_data, t_stack *a_data)
{
	char		*tmp;
	int			len;

	while (*b_data->pr != NULL)
	{
		tmp = *(b_data->cmnd - 1);
		len = ft_strlen(tmp);
		(*a_data->cmnd) = (char*)malloc(sizeof(char) * len);
		while (len)
		{
			(*a_data->cmnd)[len] = (*(b_data->cmnd - 1))[len];
			len--;
		}
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

int				*any_double(char **av, int ac, int flag)
{
	int			i;
	int			j;
	int			*arr;

	i = 1 + flag;
	j = 1 + flag;
	arr = (int *)malloc(sizeof(int) * (ac - 1 - flag));
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (NULL);
		arr[i - 1 - flag] = ft_atoi(av[i]);
		while (j < ac)
		{
			if ((ft_atoi(av[j]) == arr[i - 1 - flag]) && (j != i))
				return (NULL);
			j++;
		}
		i++;
		j = 1 + flag;
	}
	return (arr);
}

int				save_stack(int ac, char **av, t_arr *res_lst, int *flag)
{
	int			i;
	int			j;
	t_arr		*stack;
	int			*arr;

	j = ((*flag & COLOR_FLAG) ? 1 : 0) + ((*flag & VISUALIZE_FLAG) ? 1 : 0);
	j = (*flag & READFILE_FLAG) ? 0 : j;
	i = 1;
	stack = res_lst;
	if (ac - j < 2)
		return (6);
	if ((arr = any_double(av, ac, j)) == NULL)
	{
		free(arr);
		return (6);
	}
	while (i < ac - j)
	{
		create_nb_elem(arr[i - 1], &stack, i);
		i++;
	}
	free(arr);
	*flag = j;
	return (j);
}

char			*handle_exceptions(int ac, char **av, int *fd, unsigned *res)
{
	if (ac == 1)
		return ("To run Checker, please, add some numeric parameters");
	if ((*fd = read_input(ac, av, res)) == -2)
		return ("Error");
	else
		return ("");
}
