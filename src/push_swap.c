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

int		find_place(t_arr **a, int b, t_stack *a_data)
{
	int			place;
	t_arr		*pr;
	int			diff;

	diff = a_data->max - a_data->min;
	pr = *a;
	place = (*a)->content;
	while (pr)
	{
		if ((pr->content > b) && (diff > pr->content - b))
		{
			diff = pr->content - b;
			place = pr->content;
		}
		pr = pr->next;
	}
	return (place);
}

t_cmnd		choose_best(t_arr **a, t_arr **b, t_stack **a_data, t_stack *b_data)
{
	t_arr		*pr;
	t_cmnd		cmnd;
	int			i;
	int			best_place;

	i = 1;
	cmnd.c = 1000000000;
	pr = *b;
	best_place = 0;
	while (pr)
	{
		cmnd.place = find_place(a, pr->content, *a_data);
		if (calculate_comands(a, &cmnd, min_is(i, b_data->length - i),
					(*a_data)->length))
		{
			cmnd.best = pr->content;
			best_place = cmnd.place;
		}
		i++;
		pr = pr->next;
	}
	cmnd.place = best_place;
	(*a_data)->place = cmnd.place;
	(*a_data)->best = cmnd.best;
	return (cmnd);
}

int		sorting(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_cmnd		cmnd;
	int			i;
	int			j;

	while (*b && b_data->length)
	{
		cmnd = choose_best(a, b, &a_data, b_data);
		if ((cmnd.b >= cmnd.a && cmnd.a > 0) ||
				(cmnd.a >= cmnd.b && cmnd.b > 0))
		{
			i = detect_index(a, cmnd.place);
			j = detect_index(b, cmnd.best);
			if (((min_is(i, a_data->length - i)) == i - 1) &&
					(min_is(j, b_data->length - j) == j - 1))
				optimazation_rr(a, b, a_data, b_data);
			else if (((min_is(i, a_data->length - i)) == a_data->length - i + 1)
				&& (min_is(j, b_data->length - j) == b_data->length - j + 1))
				optimazation_rrr(a, b, a_data, b_data);
		}
		switch_in_b(a, b, b_data, cmnd.best);
		merge_comands(b_data, a_data);
		switch_in_a(a, b, a_data, cmnd.place);
		execute_pa(a, b, a_data, b_data);
	}
	return (0);
}

int		algorithm(int ac, char **av, unsigned flag)
{
	t_arr		*res_lst;
	t_arr		*b;
	t_stack		b_stack;
	t_stack		a_stack;
	int			j;

	res_lst = nb_lstnew();
	a_stack.flag = flag;
	b_stack.flag = flag;
	b_stack.length = 0;
	if ((save_stack(ac, av, res_lst, (int*)&flag)) == 6)
		return (write(1, "Error\n", 6));
	if (ac == 3)
	{
		if (res_lst->content > res_lst->next->content)
			return (write(1, "sa\n", 3));
		else
			return (0);
	}
	if (ac == 4)
	{
		if (res_lst->content > res_lst->next->content)
		{
			free_lst_arr(res_lst);
			return (write(1, "sa\n", 3));
		}
		else
		{
			free_lst_arr(res_lst);
			write(1, "sa\n", 3);
			return (write(1, "ra\n", 3));
		}
	}
	fill_data(res_lst, ac - (int)flag - 1, &a_stack, &b_stack);
	if (lst_sorted_ac(res_lst, 0, a_stack.length))
	{
		free_a(&res_lst, &b, &a_stack, &b_stack);
		mk_easy_sort(&res_lst, &b, &a_stack);
		(lst_sorted_ac(res_lst, 0, a_stack.length) || b_stack.length != 0) ?
				sorting(&res_lst, &b, &a_stack, &b_stack) : 0;
		while (lst_sorted_ac(res_lst, 0, a_stack.length))
		{
			j = detect_index(&res_lst, a_stack.min);
			if ((min_is(j, a_stack.length - j)) == j - 1)
				execute_ra(&res_lst, &b, 0, &a_stack);
			else
				execute_rra(&res_lst, &b, &a_stack, 1);
		}
		free_lst_arr(b);
		(*a_stack.cmnd) = NULL;
		(*b_stack.cmnd) = NULL;
	}
	(a_stack.cmnd) = NULL;
	(b_stack.cmnd) = NULL;
	j = 0;
	while ((a_stack.pr)[j] != NULL)
	{
		ft_printf("%s", (a_stack.pr)[j]);
		j++;
	}
	free(a_stack.pr);
	free(b_stack.first_elem);
	free_lst_arr(res_lst);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	char		*line;
	char		**sp_line;
	unsigned	res;

	res = 0;
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
	{
		if (fd != ac && fd != -1)
		{
			ac = fd;
			av = ft_strsplit(ft_strjoin("0 ", av[1]), ' ');
		}
		if (algorithm(ac, av, res) == 6)
			return (0);
	}
	return (0);
}
