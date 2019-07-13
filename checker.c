#include "checker.h"
#include <stdio.h>

int		create_elem(void *str, size_t len, t_list **lst)
{
	t_list	*tmp_lst;

	if ((*lst)->content != NULL)
	{
		if (!(tmp_lst = ft_lstnew(str, len)))
			return (-1);
		(*lst)->next = tmp_lst;
		*lst = tmp_lst;
	}
	else
		(*lst)->content = str;
	return (1);
}

int		lst_length(t_list *lst)
{
	t_list	*new_item;
	int 	count;

	count = 0;
	if (!lst)
		return (0);
	new_item = lst;
	while (new_item)
	{
		new_item = new_item->next;
		count++;
	}
	return (count);
}


void	executeComand(t_list **res_lst, char *line, t_list **b)
{
	int 	a_length;
	int 	b_length;

	a_length = lst_length(*res_lst);
	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
	if ((ft_strcmp(line, "sa") == 0) && a_length >= 2 )
		executeSAB(res_lst, a_length);
	else if ((ft_strcmp(line, "sb") == 0) && b_length >= 2)
		executeSAB(b, b_length);
	else if (ft_strcmp(line, "ss") == 0)
		executeSSRR(res_lst, b, a_length, b_length);
	else if (ft_strcmp(line, "pa") == 0 && b_length != 0)
		executePA(res_lst, b);
	else if (ft_strcmp(line, "pb") == 0 && a_length != 0)
		executePB(res_lst, b);
	else if (ft_strcmp(line, "ra") == 0)
		executeRAB(res_lst);
	else if (ft_strcmp(line, "rb") == 0)
		executeRAB(b);
	else if (ft_strcmp(line, "rr") == 0)
		executeSSRR(res_lst, b, 0, 0);
}


void	executeRest((t_list **res_lst, char *line, t_list **b)
{
	int 	a_length;
	int 	b_length;

	a_length = lst_length(*res_lst);
	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
	else if (ft_strcmp(line, "rra") == 0)
		executeRRA(res_lst, a_length);
//	else if (ft_strcmp(line, "rrb") == 0)
//		executeRRB(res_lst, ac - 1));
//	else if (ft_strcmp(line, "rrr") == 0)
//		executeRRR(res_lst, ac - 1));
}

int		saveStack(int ac, char **av, t_list *res_lst)
{
	int		i;
	char 	*str;
	t_list	*stack;

	i = 1;
	stack = res_lst;
	if (ac < 3)
		return (0);
	while (i < ac)
	{
		str = av[i];
		create_elem(str, ft_strlen(av[i]) + 1, &stack);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	*line;
	t_list	*res_lst;
	t_list	*b;

	res_lst = ft_lstnew(NULL, 0);
	b = ft_lstnew(NULL, 0);
	if (!saveStack(ac, av, res_lst))
		return (write(2, "Error\n", 6));
	while (get_next_line(0, &line) > 0)
	{
		executeComand(&res_lst, line, &b);
		ft_printf("%s\n", ft_list_at(res_lst, 0)->content);
//		ft_printf("%s\n", res_lst->next->content);
//		ft_printf("%s\n", b->content);
	}
}

