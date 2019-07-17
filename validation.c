#include "execute.h"
#include "checker.h"

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

void	put_string(t_list *elem)
{
	ft_printf(elem->content);
}

int		save_stack(int ac, char **av, t_list *res_lst)
{
    int		i;
    t_list	*stack;

    i = 1;
    stack = res_lst;
    if (ac < 2)
        return (0);
    while (i < ac)
    {
        if (!is_int(av[i]))
            return (write(2, "Error\n", 6));
        create_elem(av[i], ft_strlen(av[i]) + 1, &stack);
        i++;
    }
    return (1);
}