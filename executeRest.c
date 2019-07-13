#include "execute.h"
#include "checker.h"

void	executeRRA(t_list **res_lst, int a_length)
{
	t_list	*new_item;
	t_list	*tmpl;

	tmpl = *res_lst;
	new_item = ft_list_at(tmpl, a_length);
	lst_delete_last(&new_item);
	ft_lstadd(res_lst, new_item);
}
