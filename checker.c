#include "checker.h"
#include <stdio.h>
#include <limits.h>

//void	execute_rest(t_list **res_lst, char *line, t_list **b)
//{
//	int 	a_length;
//	int 	b_length;
//
//	a_length = lst_length(*res_lst);
//	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
//	if (ft_strcmp(line, "rra") == 0)
//		executeRRAB(res_lst, a_length);
//	else if (ft_strcmp(line, "rrb") == 0)
//		executeRRAB(b, b_length);
//	else if (ft_strcmp(line, "rrr") == 0)
//		executeRRR(res_lst, a_length, b, b_length);
//}
//
//void	execute_comand(t_list **res_lst, char *line, t_list **b)
//{
//	int 	a_length;
//	int 	b_length;
//
//	a_length = (*res_lst)->content == NULL ? 0 : lst_length(*res_lst);
//	b_length = (*b)->content == NULL ? 0 : lst_length(*b);
//	if ((ft_strcmp(line, "sa") == 0) && a_length >= 2)
//		executeSAB(res_lst, a_length);
//	else if ((ft_strcmp(line, "sb") == 0) && b_length >= 2)
//		executeSAB(b, b_length);
//	else if (ft_strcmp(line, "ss") == 0)
//		executeSSRR(res_lst, b, a_length, b_length);
//	else if (ft_strcmp(line, "pa") == 0 && b_length != 0)
//		executePA(res_lst, b);
//	else if (ft_strcmp(line, "pb") == 0 && a_length != 0)
//		executePB(res_lst, b);
//	else if (ft_strcmp(line, "ra") == 0)
//		executeRAB(res_lst);
//	else if (ft_strcmp(line, "rb") == 0)
//		executeRAB(b);
//	else if (ft_strcmp(line, "rr") == 0)
//		executeSSRR(res_lst, b, 0, 0);
//	else
//		execute_rest(res_lst, line, b);
//}

//int		save_stack(int ac, char **av, t_list *res_lst)
//{
//	int		i;
//	t_list	*stack;
//
//	i = 1;
//	stack = res_lst;
//	if (ac < 2)
//		return (0);
//	while (i < ac)
//	{
//		if (!is_int(av[i]))
//			return (write(2, "Error\n", 6));
//		create_elem(av[i], ft_strlen(av[i]) + 1, &stack);
//		i++;
//	}
//	return (1);
//}

//int		main(int ac, char **av)
//{
//	char	*line;
//	t_list	*res_lst;
//	t_list	*b;
//
//	res_lst = ft_lstnew(NULL, 0);
//	b = ft_lstnew(NULL, 0);
//	if (!save_stack(ac, av, res_lst))
//		return (0);
//	while (get_next_line(0, &line) > 0)
//	 {
//		if (!*line)
//			break;
//		if (!valid(line)) {
//			free(line);
//			return (write(2, "Error\n", 6));
//		}
//		execute_comand(&res_lst, line, &b);
//		free(line);
//	}
//	if ((!lst_sorted(res_lst)) || (b->content != NULL))
//		return (write(2, "KO\n", 3));
//	else
//	{
//		ft_lstiter(res_lst, put_string);
//		return (write(1, "OK\n", 3));
//	}
//}

//sa
//pb
//pb
//pb
//rr
//rrr
//sa
//pa
//pa
//pa
//
//

