#include "execute.h"
#include "checker.h"

void	executeRRAB(t_list **res_lst, int a_length)
{
	t_list	*new_item;
	t_list	*tmpl;
	t_list	**del;

	tmpl = *res_lst;
	del = res_lst;
	new_item = ft_lstnew((ft_list_at(tmpl, a_length - 1))->content, ft_strlen((ft_list_at(tmpl, a_length - 1))->content));
	while ((*del)->next)
		*del = (*del)->next;
	(*del)->content = NULL;
	ft_lstadd(&tmpl, new_item);
	*res_lst = tmpl;
}

void	*executeRRR(t_list **res_lst, int a_length, t_list **b, int b_length)
{
	executeRRAB(res_lst, a_length);
	executeRRAB(b, b_length);
}
