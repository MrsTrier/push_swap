/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:46:01 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:03:17 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

char			*handle_exceptions(int ac, char **av, int *fd, unsigned *res)
{
	if (ac == 1)
		return ("To run Checker, please, add some numeric parameters");
	if ((*fd = read_input(ac, av, res)) == -2)
		return ("Error");
	else
		return ("");
}

int				prepare_input(char ***sp_line, char *line)
{
	char		*tmp;

	tmp = ft_strjoin("0 ", line);
	*sp_line = ft_strsplit(tmp, ' ');
	free(tmp);
	free(line);
	return (count_wrds(*sp_line));
}

int				find_min(t_arr *res_lst)
{
	int			min;
	t_arr		*new_item;

	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	min = new_item->content;
	while (new_item->next)
	{
		if (min > new_item->next->content)
			min = new_item->next->content;
		new_item = new_item->next;
	}
	return (min);
}

int				find_max(t_arr *res_lst)
{
	int			max;
	t_arr		*new_item;

	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	max = new_item->content;
	while (new_item->next)
	{
		if (max < new_item->next->content)
			max = new_item->next->content;
		new_item = new_item->next;
	}
	return (max);
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

int				read_input(int ac, char **av, unsigned *res)
{
	int			fd;
	int			i;
	int			result;

	fd = -1;
	i = 1;
	while (ac > 2 ? i < 3 : i < 2)
	{
		if (!is_int(av[i]))
		{
			if (ft_strcmp("-c", av[i]) == 0)
				*res |= COLOR_FLAG;
			else if (ft_strcmp("-v", av[i]) == 0)
				*res |= VISUALIZE_FLAG;
			else if ((fd = open(av[i], O_RDONLY)) != -1)
				*res |= READFILE_FLAG;
			else if (ac == 2)
			{
				if ((result = handle_input_in_row(av)) != -1)
					return (result);
			}
			else
				return (-2);
		}
		i++;
	}
	return (fd);
}

int				count_wrds(char **sp_line)
{
	int			wrds;

	wrds = 1;
	while (sp_line[wrds] != NULL)
		wrds++;
	return (wrds);
}

void			fill_data(t_arr *a, int i, t_stack *a_data, t_stack *b_data)
{
	int			*arr;

	arr = lst_to_arr(a, i);
	a_data->length = i;
	a_data->min = find_min(a);
	a_data->max = find_max(a);
	heap_sort(i, &arr);
	a_data->mdn = arr[(a_data->length / 2)];
	a_data->cmnd = (char**)malloc(sizeof(a_data->cmnd) * 10000);
	b_data->cmnd = (char**)malloc(sizeof(b_data->cmnd) * 1000);
	a_data->pr = (a_data->cmnd);
	b_data->pr = (b_data->cmnd);
	b_data->first_elem = (b_data->cmnd);
	free(arr);
}
