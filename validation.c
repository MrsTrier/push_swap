#include "execute.h"
#include "checker.h"
#include "push_swap.h"

int 	valid(char *line)
{
	if ((ft_strcmp(line, "sa") == 0) || (ft_strcmp(line, "sb") == 0) ||
		(ft_strcmp(line, "ss") == 0) || (ft_strcmp(line, "pa") == 0) ||
		(ft_strcmp(line, "pb") == 0) || (ft_strcmp(line, "ra") == 0) ||
		(ft_strcmp(line, "rb") == 0) || (ft_strcmp(line, "rr") == 0) ||
		(ft_strcmp(line, "rra") == 0) || (ft_strcmp(line, "rrb") == 0) ||
		(ft_strcmp(line, "rrr") == 0))
		return (1);
	return (0);
}

int 	*any_double(char **av, int ac)
{
	int		i;
	int		j;
	int		curr;
	int     *arr;


	i = 1;
	j = 1;
	arr = (int *)malloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (NULL);
		arr[i - 1] = ft_atoi(av[i]);
		while (j < ac)
		{
			if ((ft_atoi(av[j]) == arr[i - 1]) && (j != i))
				return (NULL);
			j++;
		}
		i++;
		j = 1;
	}
	return (arr);
}

void	put_string(t_list *elem)
{
	ft_printf(elem->content);
}

int		save_stack(int ac, char **av, t_list_arr *res_lst)
{
    int			i;
    t_list_arr	*stack;
    int			*arr;

    i = 1;
    stack = res_lst;
    if (ac < 2)
        return (0);
	if ((arr = any_double(av, ac)) == NULL)
		return (write(2, "Error\n", 6));
    while (i < ac)
    {
        create_nb_elem(arr[i - 1], &stack);
        i++;
    }
    //Очистить arr[]!!!!
    return (1);
}