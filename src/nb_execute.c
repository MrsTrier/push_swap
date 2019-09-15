#include "execute.h"
#include "push_swap.h"

int		executeSA(t_list_arr **a, t_list_arr **b, t_stack *a_data, int ss)
{
	t_list_arr	*pr_a;
	int			tmp;

	if (!ss)
	{
		(*a_data->cmnd) = "sa\n";
		a_data->cmnd++;
		pr_a = *a;
	}
	if (a_data->length < 2)
		return (0);
	else
	{
		tmp = (nb_list_at(pr_a, 0)->content);
		nb_list_at(pr_a, 0)->content = nb_list_at(pr_a, 1)->content;
		nb_list_at(pr_a, 1)->content = tmp;
	}
	if ((a_data->flag & VISUALIZE_FLAG) && ss == 0)
		visualize(a, b, SA, a_data->flag & COLOR_FLAG ? 1 : 0);
	return (1);
}

int		executeSB(t_list_arr **a, t_list_arr **b, t_stack *b_data, int ss)
{
	t_list_arr	*pr;
	int			tmp;

	if (!ss)
	{
		(*b_data->cmnd) = "sb\n";
		b_data->cmnd++;
	}
	pr = *b;
	if (b_data->length <= 2)
		return (0);
	else
	{
		tmp = (nb_list_at(pr, 0)->content);
		nb_list_at(pr, 0)->content = nb_list_at(pr, 1)->content;
		nb_list_at(pr, 1)->content = tmp;
	}
	if ((b_data->flag & VISUALIZE_FLAG) && ss == 0)
		visualize(a, b, SB, b_data->flag & COLOR_FLAG ? 1 : 0);
	return (1);
}

void	executePA(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

	(*a_data->cmnd) = "pa\n";
	a_data->cmnd++;
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
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, PA, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	executePB(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

	(*a_data->cmnd) = "pb\n";
	a_data->cmnd++;
    //ft_printf("pb\n");
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
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, PB, a_data->flag & COLOR_FLAG ? 1 : 0);
}


void	executeRA(t_list_arr **a, t_list_arr **b, int rr, t_stack *a_data)
{
	t_list_arr	*new_item;
	int 		tmp;

	if (!rr)
	{
		(*a_data->cmnd) = "ra\n";
		a_data->cmnd++;
	}
//	if (!rr)
//		ft_printf("ra\n");
	new_item = (*a)->next;
	tmp = (*a)->content;
	free(*a);
	*a = new_item;
	nb_push_back(a, tmp);
	if ((a_data->flag & VISUALIZE_FLAG) && rr == 0)
		visualize(a, b, RA, a_data->flag & COLOR_FLAG ? 1 : 0);
}


void	executeRB(t_list_arr **a, t_list_arr **b, int rr, t_stack *b_data)
{
	t_list_arr	*new_item;
	int 		tmp;

	if (!rr)
	{
		(*b_data->cmnd) = "rb\n";
		b_data->cmnd++;
	}
	new_item = (*b)->next;
	tmp = (*b)->content;
	free(*b);
	*b = new_item;
	nb_push_back(b, tmp);
	if ((b_data->flag & VISUALIZE_FLAG) && rr == 0)
		visualize(a, b, RB, b_data->flag & COLOR_FLAG ? 1 : 0);
}


void	executeSS(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	(*a_data->cmnd) = "ss\n";
	a_data->cmnd++;
	executeSA(a, b, a_data, 1);
	executeSB(a, b, b_data, 1);
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, SS, a_data->flag & COLOR_FLAG ? 1 : 0);
}


void	executeRR(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	(*a_data->cmnd) = "rr\n";
	a_data->cmnd++;
	executeRA(a, b, 1, a_data);
	executeRB(a, b, 1, a_data);
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RR, a_data->flag & COLOR_FLAG ? 1 : 0);
}
