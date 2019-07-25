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

int     find_min(t_list *res_lst)
{
    int min;
    t_list *new_item;

    if (!res_lst)
        return (write(2, "Error\n", 6));
    new_item = res_lst;
    min = *((int *)(new_item->content));
    while (new_item->next)
    {
        if (min > *((int *)(new_item->next->content)))
            min = *((int *)(new_item->next->content));
        new_item = new_item->next;
    }
    return (min);
}

int     find_max(t_list *res_lst)
{
	int		max;
	t_list	*new_item;

	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	max = *((int *)(new_item->content));
	while (new_item->next)
	{
		if (max < *((int *)(new_item->next->content)))
			max = *((int *)(new_item->next->content));
		new_item = new_item->next;
	}
	return (max);
}

int		mk_easy_sort(t_list **a, int a_length)
{
	int i = 0;

	if (lst_sorted_ac(*a) && lst_sorted_dec(*a))
		executeSAB(a, a_length);
	else
	{
		if (find_min(*a) != (*(int *)(*a)->content))
			executeSAB(a, a_length);
		while (!lst_sorted_ac(*a))
		{
			executeRRAB(a, 3);
			executeSAB(a, a_length);
			i += 2;
		}
	}
	return (i);
}

int		free_a(t_list **a, t_list **b, t_stack *a_data, t_stack *b_data)
{
	t_list	*pr;
	int 	i = 0;

	pr = *a;
	a_data->min = find_min(*a);
	a_data->max = find_max(*a);
	a_data->mdn = (*(int *)(ft_list_at(*a, (a_data->length / 2) - 1)->content));
	while (a_data->length != 3)
	{
		if ((*(int *)pr->content) != a_data->min && (*(int *)pr->content) != a_data->max && (*(int *)pr->content) != a_data->mdn )
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

int		detect_index(t_list **a, int place)
{
	t_list	*pr;
	int		i;

	pr = *a;
	i = 1;
	while (*(int *)pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	return (i);
}

int		calculate_comands(t_list **a, int place, int b, int a_length)
{
	t_list	*pr;
	int		i;
	int 	trns;

	i = 1;
	trns = 0;
	pr = *a;
	while (*(int *)pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	trns = min_is(i, a_length - i);
	return (trns + b);
}

int		find_place(t_list **a, int b, t_stack *a_data)
{
	int		place;
	t_list	*pr;
	int		diff;

	diff = a_data->max - a_data->min;
	pr = *a;
	place = (*(int *)(*a)->content);
	while (pr)
	{
		if ((*(int *)pr->content) > b && diff > (*(int *)pr->content) - b)
		{
			diff = (*(int *)pr->content) - b;
			place = (*(int *)pr->content);
		}
		pr = pr->next;
	}
	return (place);
}

int		choose_best(t_list **a, t_list **b, t_stack *a_data, t_stack *b_data, int *place)
{
	t_list	*pr;
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
	while (i - 1 < (int)b_data->length)
	{
		*place = find_place(a, *(int *)pr->content, a_data);
		if (comands > (curr = calculate_comands(a, *place, min_is(i, b_data->length- i), a_data->length)))
		{
			best = *(int *)pr->content;
			comands = curr;
			best_place = *place;
		}
		i++;
		pr = pr->next;
	}
	*place = best_place;
	return (best);
}

void	sorting(t_list **a, t_list **b, t_stack *a_data, t_stack *b_data)
{
	t_list	*pr;
	t_list	*pr_a;
	int 	i;
	int 	j;
	int		best;
	int		place;

	i = 0;
	j = 0;
	pr = *b;
	pr_a = *a;
	while ((*b)->content != NULL)
	{
		pr = *b;
		pr_a = *a;
		best = choose_best(a, b, a_data, b_data, &place);
		i = detect_index(b, best);
		while ((*(int *)pr->content) != best)
		{
			if ((min_is(i, b_data->length - i)) == i - 1)
				executeRAB(b);
			else
				executeRRAB(b, b_data->length);
		}
		j = detect_index(a, place);
		while ((*(int *)pr_a->content) != place)
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
    t_list	*res_lst;
    t_list	*b;
	t_stack	b_stack;
	t_stack	a_stack;
    int		i;

    i = 0;
    res_lst = ft_lstnew(NULL, 0);
    b = ft_lstnew(NULL, 0);
    if (!save_stack(ac, av, res_lst))
        return (0);
	a_stack.length = (res_lst)->content == NULL ? 0 : lst_length(res_lst);
	b_stack.length = (b)->content == NULL ? 0 : lst_length(b);
	i = free_a(&res_lst, &b, &a_stack, &b_stack);
	i += mk_easy_sort(&res_lst, 3);
	sorting(&res_lst, &b, &a_stack, &b_stack);
	ft_printf("%d\n", *((int *)res_lst->content));
	ft_printf("%d\n", *((int *)res_lst->next->content));
	ft_printf("%d\n", *((int *)res_lst->next->next->content));
//	ft_printf("%d\n\n", a_length);
//	ft_printf("%d\n\n", b_length);
}