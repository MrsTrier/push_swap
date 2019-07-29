#include "execute.h"
#include "push_swap.h"

int		executeSAB(t_list_arr **res_lst, int elemNum)
{
	t_list_arr	*a;
	int			tmp;

	a = *res_lst;
	if (elemNum <= 2)
		return (0);
	else
	{
		tmp = (nb_list_at(a, 0)->content);
		nb_list_at(a, 0)->content = nb_list_at(a, 1)->content;
		nb_list_at(a, 1)->content = tmp;
	}
	return (1);
}

void	executePA(t_list_arr **a, t_list_arr **b)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

	new_a = *b;
	next = nb_list_at(new_a, 1);
	new_item = nb_lstnew();
	new_item->content = (*b)->content;
	new_item->next = NULL;
	if (*a)
		new_item->next = *a;
	*a = new_item;
	free(new_a);
	*b = next;
}

void	executePB(t_list_arr **a, t_list_arr **b)
{
	t_list_arr *new_item;
	t_list_arr *new_a;
	t_list_arr *next;

	new_a = *a;
	next = nb_list_at(new_a, 1);
	new_item = nb_lstnew();
	new_item->content = (*a)->content;
	new_item->next = NULL;
	if (*b)
		new_item->next = *b;
	*b = new_item;
	free(new_a);
	*a = next;
}

void	executeRAB(t_list_arr **a)
{
	t_list_arr	*new_item;
	int 		tmp;

	new_item = (*a)->next;
	tmp = (*a)->content;
	free(*a);
	*a = new_item;
	nb_push_back(a, tmp);
}

void	executeSSRR(t_list_arr **a, t_list_arr **b, int a_length, int b_length)
{
	if (a_length == 0 && b_length == 0)
	{
		executeRAB(a);
		executeRAB(b);
		return ;
	}
	executeSAB(a, a_length);
	executeSAB(b, b_length);
}
