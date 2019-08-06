#include "execute.h"
#include "checker.h"
#include "push_swap.h"




void	executeRRB(t_list_arr **a, t_list_arr **b, int length)
{
	t_list_arr	*tmpl;

	tmpl = nb_list_at(*b, length - 1);
	nb_list_at(*b, length - 2)->next = NULL;
	tmpl->next = *b;
	*b = tmpl;
//	if ((*b)->flag & VISUALIZE_FLAG)
//		visualize(a, b, RRB);
}

void	executeRRA(t_list_arr **a, t_list_arr **b, int length)
{
	t_list_arr	*tmpl;
	t_list_arr	*pr;

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
	executeRRA(a, b, a_length);
	executeRRB(a, b, b_length);
	if ((*a)->flag & VISUALIZE_FLAG)
		visualize(a, b, RRR);
}

