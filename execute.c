#include "execute.h"

int		executeSAB(t_list **res_lst, int elemNum)
{
	t_list	*a;
	char 	*tmp;

	a = *res_lst;
	if (elemNum <= 2)
		return (0);
	else
	{
		tmp = (ft_list_at(a, 0)->content);
		ft_list_at(a, 0)->content = ft_list_at(a, 1)->content;
		ft_list_at(a, 1)->content = tmp;
	}
	return (1);
}


void	executePA(t_list **a, t_list **b)
{
	t_list *new_item;

	new_item = ft_create_elem((*b)->content);
	new_item->next = *a;
	*a = new_item;
}

void	executePB(t_list **a, t_list **b)
{
	t_list *new_item;

	new_item = ft_create_elem((*a)->content);
	new_item->next = *b;
	*b = new_item;
}

void	executeRAB(t_list **a)
{
	t_list	*new_item;
	t_list	*tmpl;

	new_item = (*a)->next;
	tmpl = ft_lstnew((*a)->content, ft_strlen((*a)->content));
	free(*a);
	*a = new_item;
	ft_push_back(a, tmpl);
}

void	executeSSRR(t_list **a, t_list **b, int a_length, int b_length)
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
