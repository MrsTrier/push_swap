#include "checker.h"
#include <stdio.h>

void	executeRest(t_list **res_lst, char *line, t_list **b)
{
	int 	a_length;
	int 	b_length;

	a_length = lst_length(*res_lst);
	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
	if (ft_strcmp(line, "rra") == 0)
		executeRRAB(res_lst, a_length);
	else if (ft_strcmp(line, "rrb") == 0)
		executeRRAB(b, b_length);
	else if (ft_strcmp(line, "rrr") == 0)
		executeRRR(res_lst, a_length, b, b_length);
}

void	executeComand(t_list **res_lst, char *line, t_list **b)
{
	int 	a_length;
	int 	b_length;

	a_length = (*res_lst)->content == NULL ? 0 : lst_length(*res_lst);
	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
	if ((ft_strcmp(line, "sa") == 0) && a_length >= 2)
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
	else
		executeRest(res_lst, line, b);
}

int		saveStack(int ac, char **av, t_list *res_lst)
{
	int		i;
	char 	*str;
	t_list	*stack;

	i = 1;
	stack = res_lst;
	if (ac < 2)
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
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		executeComand(&res_lst, line, &b);
		ft_printf("%s\n", ft_list_at(res_lst, 0)->content);
//		ft_printf("%s\n", ft_list_at(res_lst, 2)->content);
//		ft_printf("%s\n", res_lst->content);
//		ft_printf("%s\n", b->content);
//		ft_printf("%s\n", ft_list_at(res_lst, 0)->content);
	}
	ft_printf("dad");
	if ((!lst_sorted(res_lst, f)) && (b->content != NULL))
		return (write(2, "Error\n", 6));
	return (write(1, "uraa\n", 5));
}

//sa
//pb
//pb
//pb
//rr
//rrr
//sa
//pa

