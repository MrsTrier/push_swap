#include "execute.h"
#include "push_swap.h"

int		executeSAB(t_list_arr **a, t_list_arr **b, int elemNum, int a_or_b, int ss)
{
	t_list_arr	*pr_a;
	int			tmp;

    ft_printf(a_or_b ? "sa\n" : "sb\n");
	pr_a = a_or_b ? *a : *b;
	if (elemNum <= 2)
		return (0);
	else
	{
		tmp = (nb_list_at(pr_a, 0)->content);
		nb_list_at(pr_a, 0)->content = nb_list_at(pr_a, 1)->content;
		nb_list_at(pr_a, 1)->content = tmp;
	}
	if (((*a)->flag & VISUALIZE_FLAG) && ss == 0)
		visualize(a, b, a_or_b ? SA : SB);
	return (1);
}

void	executePA(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

    ft_printf("pa\n");
	new_a = *b;
	next = nb_list_at(new_a, 1);
	new_item = nb_lstnew();
	new_item->content = (*b)->content;
	new_item->next = NULL;
	new_item->next = *a;
	*a = new_item;
	free(new_a);
	*b = next;
	a_data->length++;
	b_data->length--;
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, PA);
}

void	executePB(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

    ft_printf("pb\n");
	new_a = *a;
	next = nb_list_at(new_a, 1);
	new_item = nb_lstnew();
	new_item->content = (*a)->content;
	new_item->next = NULL;
	if (b_data->length != 0)
		new_item->next = *b;
	*b = new_item;
	free(new_a);
	*a = next;
	b_data->length++;
	a_data->length--;
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, PB);
}

void	executeRAB(t_list_arr **a, t_list_arr **b, int a_or_b, int rr)
{
	t_list_arr	*new_item;
	int 		tmp;

	if (!rr)
	    ft_printf(a_or_b ? "ra\n" : "rb\n");
	new_item = a_or_b ? (*a)->next : (*b)->next;
	tmp = a_or_b ? (*a)->content : (*b)->content;
	a_or_b ? free(*a) : free(*b);
	if (a_or_b)
		*a = new_item;
	else
		*b = new_item;
	nb_push_back(a_or_b ? a : b, tmp);
//	if ((*a)->flag & COLOR_FLAG)
//		visualize_color(a, b, a_or_b ? "ra" : "rb");
	if (((*a)->flag & VISUALIZE_FLAG) && rr == 0)
		visualize(a, b, a_or_b ? RA : RB);
}

void	executeSSRR(t_list_arr **a, t_list_arr **b, t_stack *a_data, int rr)
{
	int b_length;

	ft_printf(rr ? "rr\n" : "ss\n");
	b_length = a_data->tot_len - a_data->length;
	if (rr)
	{
		executeRAB(a, b, 1, 1);
		executeRAB(a, b, 0, 1);
	}
	else
	{
		executeSAB(a, b, a_data->length, 1, 1);
		executeSAB(a, b, b_length, 0, 1);
	}
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, rr ? RR : SS);
}
