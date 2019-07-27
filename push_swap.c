#include "push_swap.h"

int     *lst_to_arr(t_list *lst, int ac)
{
    t_list  *new_item;
    int     *arr;
    int     i;

    if (!lst)
        return (NULL);
    i = 0;
    new_item = lst;
    arr = (int *)malloc(sizeof(int) * ac);
    while (new_item)
    {
        arr[i] = ft_atoi(new_item->content);
        new_item = new_item->next;
        i++;
    }
    return (arr);
}

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

int     find_max(t_list_arr	*res_lst, int len)
{
	int			max;
	t_list_arr	*new_item;
	int 		i;

	i = 0;
	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	max = new_item->content;
	while (i < len)
	{
		if (max < new_item->next->content)
			max = (int)new_item->next->content;
		new_item = new_item->next;
		i++;
	}
	return (max);
}

//int		mk_easy_sort(t_list_arr **a, int a_length)
//{
//	int i = 0;
//
//	if (lst_sorted_ac(*a) && lst_sorted_dec(*a))
//		executeSAB(a, a_length);
//	else
//	{
//		if (find_min(*a) != ((*a)->content))
//			executeSAB(a, a_length);
//		while (!lst_sorted_ac(*a))
//		{
//			executeRRAB(a, 3);
//			executeSAB(a, a_length);
//			i += 2;
//		}
//	}
//	return (i);
//}

int		free_a(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr	*pr;
	int			i;

	i = 0;
	pr = *a;
	//a_data->min = find_min(*a);
	a_data->max = find_max(a, a_data->length);
	ft_printf("%d\n", a_data->max);
	return (0);
	a_data->mdn = ((nb_list_at(*a, (a_data->length / 2) - 1)->content));
	while (a_data->length != 3)
	{
		if ((pr->content != a_data->min) && (pr->content != a_data->max) && (pr->content != a_data->mdn))
		{
			executePB(a, b);
			i++;
			b_data->length += 1;
//			if (*b_length >= 3)
//				if ((*(int *)(*b)->content) > (*(int *)(*b)->next->content))
//				{
//					executeSAB(b, b_length);
//					i++;
//				}
			a_data->length -= 1;
		}
		else
		{
			executeRAB(a);
			i++;
		}
		pr = pr->next;
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

int		detect_index(t_list_arr **a, int place)
{
	t_list_arr	*pr;
	int		i;

	pr = *a;
	i = 1;
	while (pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	return (i);
}

int		calculate_comands(t_list_arr **a, int place, int b, int a_length)
{
	t_list_arr	*pr;
	int			i;
	int			trns;

	i = 1;
	trns = 0;
	pr = *a;
	while (pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	trns = min_is(i, a_length - i);
	return (trns + b);
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
		if (pr->content > b && diff > pr->content - b)
		{
			diff = pr->content - b;
			place = pr->content;
		}
		pr = pr->next;
	}
	return (place);
}

int		choose_best(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data, int *place)
{
	t_list_arr	*pr;
	int		i;
	int		curr;
	int		comands;
	int		best;
	int		best_place;

	i = 1;
	comands = 100000000000000;
	pr = *b;
	best = 0;
	best_place = 0;
	while (i - 1 < b_data->length)
	{
		*place = find_place(a, pr->content, a_data);
		if (comands > (curr = calculate_comands(a, *place, min_is(i, b_data->length- i), a_data->length)))
		{
			best = pr->content;
			comands = curr;
			best_place = *place;
		}
		i++;
		pr = pr->next;
	}
	*place = best_place;
	return (best);
}

void	sorting(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr	*pr;
	t_list_arr	*pr_a;
	int			i;
	int 		j;
	int			best;
	int			place;

	i = 0;
	j = 0;
	pr = *b;
	pr_a = *a;
	while (*b)
	{
		pr = *b;
		pr_a = *a;
		best = choose_best(a, b, a_data, b_data, &place);
		i = detect_index(b, best);
		while (pr->content != best)
		{
			if ((min_is(i, b_data->length - i)) == i - 1)
				executeRAB(b);
			else
				executeRRAB(b, b_data->length);
		}
		j = detect_index(a, place);
		while (pr_a->content != place)
		{
			if ((min_is(j, a_data->length - j)) == j - 1)
				executeRRAB(a, a_data->length);
			else
				executeRAB(a);
			pr_a = *a;
		}
		executePA(a, b);
		a_data->length++;
		pr_a = *a;
		b_data->length--;
	}
}

int		main(int ac, char **av)
{
    t_list_arr	*res_lst;
    t_list_arr	*b;
	t_stack		b_stack;
	t_stack		a_stack;
    int			i;

    i = 0;
    res_lst = nb_lstnew();
    b = nb_lstnew();
    if (!save_stack(ac, av, res_lst))
        return (0);
	a_stack.length = ac - 1;
//	ft_printf("%d\n", a_stack.length);
	b_stack.length = 0;
	i = free_a(&res_lst, &b, &a_stack, &b_stack);
//	i += mk_easy_sort(&res_lst, 3);
//	sorting(&res_lst, &b, &a_stack, &b_stack);
	ft_printf("%d\n", res_lst->content);
	ft_printf("%d\n", res_lst->next->content);
	ft_printf("%d\n", res_lst->next->next->content);
//	ft_printf("%d\n\n", a_length);
//	ft_printf("%d\n\n", b_length);
}