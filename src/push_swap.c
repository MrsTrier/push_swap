/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:45:55 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 20:05:54 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "execute.h"

int				check_for_small_sequence(int ac, t_arr **res_lst)
{
	if (ac == 3)
	{
		if ((*res_lst)->content > (*res_lst)->next->content)
			return (write(1, "sa\n", 3));
		else
			return (3);
	}
	if (ac == 4)
	{
		if ((*res_lst)->content > (*res_lst)->next->content)
		{
			free_lst_arr(*res_lst);
			return (write(1, "sa\n", 3));
		}
		else
		{
			free_lst_arr(*res_lst);
			write(1, "sa\n", 3);
			return (write(1, "ra\n", 3));
		}
	}
	return (0);
}

void			check_for_unordered_sequence(t_arr **res_lst, t_stack *a_stack,
															t_stack *b_stack)
{
	t_arr		*b;
	int			j;

	if (lst_sorted_ac(*res_lst, 0, a_stack->length))
	{
		free_a(res_lst, &b, a_stack, b_stack);
		mk_easy_sort(res_lst, &b, a_stack);
		(lst_sorted_ac(*res_lst, 0, a_stack->length) || b_stack->length != 0) ?
		sorting(res_lst, &b, a_stack, b_stack) : 0;
		while (lst_sorted_ac(*res_lst, 0, a_stack->length))
		{
			j = detect_index(res_lst, a_stack->min);
			if ((min_is(j, a_stack->length - j)) == j - 1)
				execute_ra(res_lst, &b, 0, a_stack);
			else
				execute_rra(res_lst, &b, a_stack, 1);
		}
		if (a_stack->length > 3)
			free_lst_arr(b);
		(*a_stack->cmnd) = NULL;
		(*b_stack->cmnd) = NULL;
	}
	(a_stack->cmnd) = NULL;
	(b_stack->cmnd) = NULL;
}

int				algorithm(int ac, char **av, unsigned flag)
{
	t_arr		*res_lst;
	t_stack		b_stack;
	t_stack		a_stack;
	int			j;

	res_lst = nb_lstnew();
	a_stack.flag = flag;
	b_stack.flag = flag;
	b_stack.length = 0;
	if ((save_stack(ac, av, res_lst, (int*)&flag)) == 6)
		return (write(1, "Error\n", 6));
	if (check_for_small_sequence(ac, &res_lst) == 3)
		return (0);
	fill_data(res_lst, ac - (int)flag - 1, &a_stack, &b_stack);
	check_for_unordered_sequence(&res_lst, &a_stack, &b_stack);
	j = 0;
	while ((a_stack.pr)[j] != NULL)
	{
		ft_printf("%s", (a_stack.pr)[j]);
		j++;
	}
	let_me_free(&res_lst, &a_stack, &b_stack);
	return (0);
}

void			for_numbers_in_one_row(int fd, int ac, unsigned res, char **av)
{
	char		*tmp;

	if (fd != ac && fd != -1)
	{
		ac = fd;
		tmp = ft_strjoin("0 ", av[1]);
		av = ft_strsplit(tmp, ' ');
		free(tmp);
		algorithm(ac, av, res);
		free_arr(av);
		free(av);
	}
	else
		algorithm(ac, av, res);
}

int				main(int ac, char **av)
{
	int			fd;
	char		*line;
	char		**sp_line;
	unsigned	res;

	if (ac == 1)
		return (0);
	if ((fd = read_input(ac, av, &res)) == -2)
		return (write(1, "Error\n", 6));
	if (res & READFILE_FLAG)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!*line)
				break ;
			ac = prepare_input(&sp_line, line);
			if (algorithm(ac, sp_line, res) == 6)
				return (0);
			free_arr(sp_line);
			free(sp_line);
		}
	}
	else
		for_numbers_in_one_row(fd, ac, res, av);
	return (0);
}
