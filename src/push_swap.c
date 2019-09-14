#include "push_swap.h"
# include "execute.h"

int		easy(t_list_arr **a, t_stack *a_data)
{
	int i;
	int j;

	i = detect_index(a, a_data->min);
	j = detect_index(a, a_data->max);
	if (i - j == 1 || i - j == -2)
		return (0);
	return (1);
}

int		mk_easy_sort(t_list_arr **a, t_list_arr **b, t_stack *a_data)
{
	int i;

	i = 0;
	if (easy(a, a_data))
	{
		executeSA(a, b, a_data, 0);
		i++;
	}
	return (i);
}

int		free_a(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	int		i;
	int		j;

	j = a_data->length;
	i = 0;
	while (a_data->length != 3)
	{
//		while (j > 0)
//		{
//			if (((*a)->content != a_data->min) && ((*a)->content != a_data->max) && ((*a)->content != a_data->mdn))
//				executePB(a, b, a_data, b_data);
//			else
//				executeRA(a, b, 0, a_data);
//			j--;
//			i++;
//			((*a)->content < a_data->mdn) ? executeRA(a, b, 0, a_data) : executePB(a, b, a_data, b_data);
//		}
		(((*a)->content != a_data->min) && ((*a)->content != a_data->max) && ((*a)->content != a_data->mdn)) ? executePB(a, b, a_data, b_data) : executeRA(a, b, 0, a_data);//&&	((*a)->content != a_data->mdn))
			i++;
	}
	return (i);
}

int 	min_is(int up, int bottom)
{
	if (up <= bottom + 1)
		return (up - 1);
	else
		return (bottom + 1);
}

int		calculate_comands(t_list_arr **a, t_cmnd *cmnd, int b, int a_length)
{
	int			i;
	int			trns_to_place;

	i = detect_index(a, cmnd->place);
	trns_to_place = min_is(i, a_length - i);
	if (trns_to_place + b < cmnd->c)
	{
		cmnd->c = trns_to_place + b;
		cmnd->b = b;
		cmnd->a = cmnd->c - cmnd->b;
		return (1);
	}
	return (0);
}

int		find_place(t_list_arr **a, int b, t_stack *a_data)
{
	int			place;
	t_list_arr	*pr;
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

t_cmnd		choose_best(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr	*pr;
	t_cmnd		cmnd;
	int			i;
	int			best_place;

	i = 1;
	cmnd.c = 1000000000;
	pr = *b;
	best_place = 0;
	while (pr)
	{
		cmnd.place = find_place(a, pr->content, a_data);
		if (calculate_comands(a, &cmnd, min_is(i, b_data->length - i), a_data->length))
		{
			cmnd.best = pr->content;
			best_place = cmnd.place;
		}
		i++;
		pr = pr->next;
	}
	cmnd.place = best_place;
	return (cmnd);
}


int 	switch_in_b(t_list_arr **a, t_list_arr **b, t_stack *b_data, int nb)
{
	int c;
	int i;

	c = 0;
	i = detect_index(b, nb);
	while ((*b)->content != nb)
	{
		c++;
		if ((min_is(i, b_data->length - i)) == i - 1)
			executeRB(a, b, 0, b_data);
		else
			executeRRB(a, b, b_data, 1);
	}
	return (c);
}

int 	switch_in_a(t_list_arr **a, t_list_arr **b, t_stack *a_data, int nb)
{
	int c;
	int i;

	c = 0;
	i = detect_index(a, nb);
	while ((*a)->content != nb)
	{
		c++;
		if ((min_is(i, a_data->length - i)) == i - 1)
			executeRA(a, b, 0, a_data);
		else
			executeRRA(a, b, a_data, 1);
	}
	return (c);
}

int		optimazationRR(t_list_arr **a, t_list_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != cmnd.place) && ((*b)->content != cmnd.best))
	{
		executeRR(a, b, a_data, b_data);
		c++;
	}
	return (c);
}

int		optimazationRRR(t_list_arr **a, t_list_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data)
{
	int c;

	c = 0;
	while (((*a)->content != cmnd.place) && ((*b)->content != cmnd.best))
	{
		executeRRR(a, a_data, b, b_data);
		c++;
	}
	return (c);
}

int		sorting(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_cmnd		cmnd;
	int 		c;
	int			i;
	int			j;

	c = 0;
	while (*b && b_data->length)
	{
		cmnd = choose_best(a, b, a_data, b_data);
		if ((cmnd.b >= cmnd.a && cmnd.a > 0) || (cmnd.a >= cmnd.b && cmnd.b > 0))
		{
			i = detect_index(a, cmnd.place);
			j = detect_index(b, cmnd.best);
			if (((min_is(i, a_data->length - i)) == i - 1) &&
					(min_is(j, b_data->length - j) == j - 1))
				c += optimazationRR(a, b, cmnd, a_data, b_data);
			else if (((min_is(i, a_data->length - i)) == a_data->length - i + 1)
					&& (min_is(j, b_data->length - j) == b_data->length - j + 1))
				c += optimazationRRR(a, b, cmnd, a_data, b_data);
			else
				c += 0;
		}
		c += switch_in_b(a, b, b_data, cmnd.best);
		if (*b_data->pr != NULL)
		{
			(*a_data->cmnd) = *(b_data->cmnd - 1);
			a_data->cmnd++;
		}
		c += switch_in_a(a, b, a_data, cmnd.place);
		executePA(a, b, a_data, b_data);
		c++;
	}
	return (c);
}

int     how_much_sorted(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	int     i;
	int     pb;

	if ((i = lst_sorted_ac(*a)) != 0)
	{
		pb = a_data->length - i;
		if (i >= (a_data->length / 2))
		{
			while (a_data->length - i)
			{
				executeRRA(a, b, a_data, 1);
				i++;
			}
			while (pb)
			{
				executePB(a, b, a_data, b_data);
				pb--;
			}
		}
		else
			return (0);
	}
	return (1);

}

int 	algorithm(int ac, char **av, unsigned flag, int *i)
{
	t_list_arr	*res_lst;
	t_list_arr	*b;
	t_stack		b_stack;
	t_stack		a_stack;
	int 		j;
	int 		h;

	h = 0;
	res_lst = nb_lstnew();
	b = nb_lstnew();
	a_stack.flag = flag;
	b_stack.flag = flag;
	b_stack.length = 0;
	if ((save_stack(ac, av, res_lst, (int*)&flag)) == 6)
		return (write(2, "Error\n", 6));
	fill_data(res_lst, ac - (int)flag - 1, &a_stack, &b_stack);
	if (lst_sorted_ac(res_lst))
	{
		if (!(how_much_sorted(&res_lst, &b, &a_stack, &b_stack)))
		{
			*i = free_a(&res_lst, &b, &a_stack, &b_stack);
			*i += mk_easy_sort(&res_lst, &b, &a_stack);
		}
//		ft_printf(*a_stack.pr);
//		ft_printf("%s\n", *a_stack.cmnd);
		*i += sorting(&res_lst, &b, &a_stack, &b_stack);
//		while (res_lst->next)
//		{
//			ft_printf("%d\n", res_lst->content);
//			res_lst = res_lst->next;
//		}
//		ft_printf("%d\n", res_lst->content);
		while (lst_sorted_ac(res_lst))
		{
			j = detect_index(&res_lst, a_stack.min);
			if ((min_is(j, a_stack.length - j)) == j - 1)
				executeRA(&res_lst, &b, 0, &a_stack);
			else
				executeRRA(&res_lst, &b, &a_stack, 1);
			*i += 1;
		}
		(*a_stack.cmnd) = NULL;
	}
//	ft_putstr(a_stack.pr);
//	while (res_lst->next)
//	{
//		ft_printf("%d\n", res_lst->content);
//		res_lst = res_lst->next;
//	}
//	ft_printf("%d\n", res_lst->content);
	(a_stack.cmnd) = NULL;
//	ft_printf("\n\n");
	while ((a_stack.pr)[h] != NULL)
	{
		ft_printf("%s", (a_stack.pr)[h]);
		h++;
	}
	free_lst_arr(res_lst);
	free_lst_arr(b);
	return (0);
}

int		main(int ac, char **av)
{
	int			i;
	int			k;
	int			fd;
	char 		*line;
	char 		**sp_line;
	unsigned	res;
	char        *tmp;

	i = 0;
	k = 0;
	if (ac == 1)
		return 0;
	if ((fd = read_input(ac, av, &res)) == -2)
		return (write(2, "Error\n", 6));
	if (!(res & READFILE_FLAG))
	{
		if (algorithm(ac, av, res, &i) == 6)
			return (0);
		ft_printf("i : %d\n", i);
		ft_printf("k : %d\n", k);
	}
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!*line)
				break;
			sp_line = ft_strsplit(tmp = ft_strjoin("0 ", line), ' ');
			ac = count_wrds(sp_line);
			if (algorithm(ac, sp_line, res, &i) == 6)
				return (0);
			if (i > 12)
			{
				ft_printf("i > 12 : %d\n", i);
				k++;
			}
			else
				ft_printf("i : %d\n", i);
			while (ac != -1)
			{
				free(sp_line[ac]);
				ac--;
			}
			free(tmp);
			free(line);
			free(sp_line);
		}
	}
	return (0);
}

