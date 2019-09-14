#include "execute.h"
#include "checker.h"
#include "push_swap.h"

void	executeRRB(t_list_arr **a, t_list_arr **b, t_stack *b_data, int rrr)
{
	t_list_arr	*tmpl;

	if (rrr)
	{
		(*b_data->cmnd) = "rrb\n";
		b_data->cmnd++;
	}
	tmpl = nb_list_at(*b, b_data->length - 1);
	nb_list_at(*b, b_data->length - 2)->next = NULL;
	tmpl->next = *b;
	*b = tmpl;
	if (b_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRB, b_data->flag & COLOR_FLAG ? 1 : 0);
}

void	executeRRA(t_list_arr **a, t_list_arr **b, t_stack *a_data, int rrr)
{
	t_list_arr	*tmpl;
	t_list_arr	*pr;

    if (rrr)
	{
		(*a_data->cmnd) = "rra\n";
		a_data->cmnd++;
	}
	pr = *a;
	tmpl = nb_list_at(pr, a_data->length - 1);
    nb_list_at(*a, a_data->length - 2)->next = NULL;
	tmpl->next = *a;
	*a = tmpl;
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRA, a_data->flag & COLOR_FLAG ? 1 : 0);
}

void	executeRRR(t_list_arr **a, t_stack *a_data, t_list_arr **b, t_stack *b_data)
{
	executeRRA(a, b, a_data, 0);
	executeRRB(a, b, b_data, 0);
	if (a_data->flag & VISUALIZE_FLAG)
		visualize(a, b, RRR, a_data->flag & COLOR_FLAG ? 1 : 0);
}

