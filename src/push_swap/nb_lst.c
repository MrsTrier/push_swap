#include "libft.h"

int		detect_index(t_list_arr **a, int place, int lenght)
{
	t_list_arr	*pr;
	int			i;

	pr = *a;
	i = 1;
	while (pr->content != place)
	{
		i++;
		pr = pr->next;
	}
	return (i);
}

void		free_lst_arr(t_list_arr *lst)
{
    t_list_arr	*tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}


