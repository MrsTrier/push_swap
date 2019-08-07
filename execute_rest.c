#include "execute.h"
#include "checker.h"
#include "push_swap.h"

void	executeRRB(t_list_arr **a, t_list_arr **b, int length, int rrr)
{
	t_list_arr	*tmpl;

	if (rrr)
        ft_printf("rrb\n");
	tmpl = nb_list_at(*b, length - 1);
	nb_list_at(*b, length - 2)->next = NULL;
	tmpl->next = *b;
	*b = tmpl;
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, RRB);
}

void	executeRRA(t_list_arr **a, t_list_arr **b, int length, int rrr)
{
	t_list_arr	*tmpl;
	t_list_arr	*pr;

    if (rrr)
        ft_printf("rra\n");
	pr = *a;
	tmpl = nb_list_at(pr, length - 1);
    nb_list_at(*a, length - 2)->next = NULL;
	tmpl->next = *a;
	*a = tmpl;
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, RRA);
}

void	executeRRR(t_list_arr **a, int a_length, t_list_arr **b, int b_length)
{
	executeRRA(a, b, a_length, 0);
	executeRRB(a, b, b_length, 0);
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, RRR);
}

