#include "libft.h"

int     *lst_to_arr(t_list_arr *lst, int ac)
{
	t_list_arr  *new_item;
	int     *arr;
	int     i;

	if (!lst)
		return (NULL);
	i = 0;
	new_item = lst;
	arr = (int *)malloc(sizeof(int) * ac);
	while (new_item->next)
	{
		arr[i] = new_item->content;
		new_item = new_item->next;
		i++;
	}
	arr[i] = new_item->content;
	return (arr);
}

int		detect_index(t_list_arr **a, int place)
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

t_list_arr	*nb_list_at(t_list_arr *begin_list, unsigned int nbr)
{
    unsigned int i;

    i = 0;
    if (!(begin_list))
        return (NULL);
    while (i < nbr)
    {
        begin_list = begin_list->next;
        i++;
    }
    if (i == nbr)
        return (begin_list);
    return (NULL);
}
