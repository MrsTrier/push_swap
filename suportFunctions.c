#include "execute.h"

void	lst_delete_last(t_list **start)
{
	t_list		*lst;

	lst = *start;
	if (!(*start))
		return ;
	else
	{
		while (lst->next)
			lst = lst->next;
		free(lst);
	}
}
