/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:08 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 20:11:29 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <limits.h>

void	execute_rest(t_arr **res_lst, t_arr **b, t_stack *a_data,
										t_stack *b_data)
{
	if (ft_strcmp(b_data->cmnd[0], "rra") == 0 && a_data->length > 1)
		execute_rra(res_lst, b, a_data, 1);
	else if (ft_strcmp(b_data->cmnd[0], "rrb") == 0 && b_data->length > 1)
		execute_rrb(res_lst, b, b_data, 1);
	else if (ft_strcmp(b_data->cmnd[0], "rrr") == 0 &&
								a_data->length > 1 && b_data->length > 1)
		execute_rrr(res_lst, a_data, b, b_data);
}

void	execute_comand(t_arr **res_lst, t_arr **b,
								t_stack *a_data, t_stack *b_data)
{
	if ((ft_strcmp(b_data->cmnd[0], "sa") == 0) && a_data->length >= 2)
		execute_sa(res_lst, b, a_data, 0);
	else if ((ft_strcmp(b_data->cmnd[0], "sb") == 0) && b_data->length >= 2)
		execute_sb(res_lst, b, a_data, 0);
	else if (ft_strcmp(b_data->cmnd[0], "ss") == 0 &&
								a_data->length >= 2 && b_data->length >= 2)
		execute_ss(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "pa") == 0 && b_data->length > 0)
		execute_pa(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "pb") == 0 && a_data->length > 0)
		execute_pb(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "ra") == 0 && a_data->length > 1)
		execute_ra(res_lst, b, 0, a_data);
	else if (ft_strcmp(b_data->cmnd[0], "rb") == 0 && a_data->length > 1)
		execute_rb(res_lst, b, 0, a_data);
	else if (ft_strcmp(b_data->cmnd[0], "rr") == 0 &&
									b_data->length > 1 && a_data->length > 1)
		execute_rr(res_lst, b, a_data, b_data);
	else
		execute_rest(res_lst, b, a_data, b_data);
}

int		manage_comands(t_arr **res_lst, t_arr **b,
						t_stack *a_stack, t_stack *b_stack)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!*line)
			break ;
		if (!valid(line))
		{
			free(line);
			return (write(2, "Error\n", 6));
		}
		(b_stack->cmnd)[0] = ft_strdup(line);
		execute_comand(res_lst, b, a_stack, b_stack);
		free(line);
		free(*b_stack->cmnd);
	}
	return (1);
}

int		execute(int ac, char **av, unsigned flag)
{
	t_stack		b_stack;
	t_stack		a_stack;
	t_arr		*res_lst;
	t_arr		*b;

	res_lst = nb_lstnew();
	b = nb_lstnew();
	a_stack.flag = flag;
	b_stack.flag = flag;
	b_stack.length = 0;
	if ((save_stack(ac, av, res_lst, (int*)&flag)) == 6)
		return (write(2, "Error\n", 6));
	fill_data(res_lst, ac - 1 - (int)flag, &a_stack, &b_stack);
	if (manage_comands(&res_lst, &b, &a_stack, &b_stack) == 6)
		return (0);
	if ((lst_sorted_ac(res_lst, 0, a_stack.length)) || b_stack.length != 0)
		return (write(1, "KO\n", 3));
	else
		return (write(1, "OK\n", 3));
}

int		main(int ac, char **av)
{
	char		*line;
	int			fd;
	unsigned	res;
	char		**sp_line;

	ft_printf("%s", handle_exceptions(ac, av, &fd, &res));
	if (fd != ac && fd != -1 && !(res & READFILE_FLAG))
	{
		ac = fd;
		av = ft_strsplit(ft_strjoin("0 ", av[1]), ' ');
		execute(ac, av, res);
	}
	else if (!(res & READFILE_FLAG))
		execute(ac, av, res);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!*line)
				break ;
			ac = prepare_input(&sp_line, line);
			execute(ac, sp_line, res);
			free(sp_line);
		}
	}
}
