#include "push_swap.h"
# include "execute.h"



int     find_min(t_list_arr *res_lst)
{
    int			min;
    t_list_arr	*new_item;

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

int     find_max(t_list_arr	*res_lst)
{
	int			max;
	t_list_arr	*new_item;

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

int		easy(t_list_arr **a, t_stack *a_data)
{
	int i;
	int j;

	i = detect_index(a, a_data->min, a_data->length);
	j = detect_index(a, a_data->max, a_data->length);
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
		while (j > 0)
		{
			if (((*a)->content != a_data->min) && ((*a)->content != a_data->max) && ((*a)->content != a_data->mdn))
				((*a)->content < a_data->mdn) ? executeRA(a, b, 0, a_data) : executePB(a, b, a_data, b_data);
			else
				executeRA(a, b, 0, a_data);
			j--;
			i++;
		}
		(((*a)->content != a_data->min) && ((*a)->content != a_data->max) &&
			((*a)->content != a_data->mdn)) ?
			executePB(a, b, a_data, b_data) : executeRA(a, b, 0, a_data);
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

	i = detect_index(a, cmnd->place, a_length);
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
	cmnd.c = 100000000000000;
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
	i = detect_index(b, nb, b_data->length);
	while ((*b)->content != nb)
	{
		c++;
		if ((min_is(i, b_data->length - i)) == i - 1)
			executeRB(a, b, b_data, 0);
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
	i = detect_index(a, nb, a_data->length);
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

//int		optimazation(t_list_arr **a, t_list_arr **b, t_cmnd cmnd, t_stack a_data, t_stack b_data)
//{
//	int c;
//
//	c = 0;
//	while ((*a)->content != cmnd.place && (*b)->content != cmnd.best)
//	{
//		if ((min_is(cmnd.a, data->length - cmnd.a)) == cmnd.a - 1)
//		{
//			executeRR(a, b, data, 1);
//			c++;
//		}
//		else
//		{
//			executeRRR(a, data, b, data->tot_len - data->length);
//			c++;
//		}
//	}
//	return (c);
//}

int		sorting(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_cmnd		cmnd;
	int 		c;

	c = 0;
	while (*b)
	{
		cmnd = choose_best(a, b, a_data, b_data);
//		if ((cmnd.b >= cmnd.a && cmnd.a > 0) || (cmnd.a >= cmnd.b && cmnd.b > 0))
//			c += optimazation(a, b, cmnd, a_data);
		c += switch_in_b(a, b, b_data, cmnd.best);
		c += switch_in_a(a, b, a_data, cmnd.place);
		executePA(a, b, a_data, b_data);
		c++;
	}
	return (c);
}

void	fill_data(t_list_arr *a, int ac, t_stack *a_data, int i)
{
	int			*arr;

	arr = lst_to_arr(a, ac - 1 - i);
	a_data->length = ac - 1 - i;
	a_data->tot_len = a_data->length;
	a_data->min = find_min(a);
	a_data->max = find_max(a);
	heap_sort(ac - 1 - i, &arr);
	a_data->mdn = arr[(a_data->length / 2)];
	free(arr);
}

int 	read_input(int ac, char **av, unsigned *res)
{
	int			fd;
	int			i;

	fd = -1;
	i = 1;
	*res = 0;
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
			else
				return (-2);
		}
		i++;
	}
	return (fd);
}



int 	algorithm(int ac, char **av, unsigned flag, int *i)
{
	t_list_arr	*res_lst;
	t_list_arr	*b;
	t_stack		b_stack;
	t_stack		a_stack;
	int 		j;

	j = ((flag & COLOR_FLAG) ? 1 : 0) + ((flag & VISUALIZE_FLAG) ? 1 : 0);
	j = (flag & READFILE_FLAG) ? 0 : j;
	res_lst = nb_lstnew();
	b = nb_lstnew();
	a_stack.flag = flag;
	b_stack.flag = flag;
	b_stack.length = 0;
	if (!save_stack(ac, av, res_lst, j))
		return (write(2, "Error\n", 6));
	fill_data(res_lst, ac, &a_stack, j);
	if (!lst_sorted_ac(res_lst))
	{
		*i = free_a(&res_lst, &b, &a_stack, &b_stack);
		*i += mk_easy_sort(&res_lst, &b, &a_stack);
		*i += sorting(&res_lst, &b, &a_stack, &b_stack);
		while (!lst_sorted_ac(res_lst))
		{
			executeRRA(&res_lst, &b, &a_stack, 1);
			*i += 1;
		}
	}
//	while (res_lst->next)
//	{
//		ft_printf("%d\n", res_lst->content);
//		res_lst = res_lst->next;
//	}
//	ft_printf("%d\n", res_lst->content);
	free_lst_arr(res_lst);
	free_lst_arr(b);
}

int 	count_wrds(char **sp_line)
{
	int 	wrds;

	wrds = 1;
	while (sp_line[wrds] != NULL)
		wrds++;
	return (wrds);
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
	if ((fd = read_input(ac, av, &res)) == -2)
		return (write(2, "Error\n", 6));
	if (!(res & READFILE_FLAG))
		algorithm(ac, av, res, &i);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!*line)
				break;
			sp_line = ft_strsplit(tmp = ft_strjoin("0 ", line), ' ');
			ac = count_wrds(sp_line);
			algorithm(ac, sp_line, res, &i);
			if (i > 12)
			{
				ft_printf("i>12 : %d\n", i);
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
	ft_printf("k : %d\n", k);
	return (0);
}