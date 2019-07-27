#include "libft.h"

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
