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
//		executeSA(res_lst, a_length);
//	else if ((ft_strcmp(line, "sb") == 0) && b_length >= 2)
//		executeSB(b, b_length);
//	else if (ft_strcmp(line, "ss") == 0)
//		executeSS(res_lst, b, a_length, b_length);
//	else if (ft_strcmp(line, "pa") == 0 && b_length != 0)
//		executePA(res_lst, b);
//	else if (ft_strcmp(line, "pb") == 0 && a_length != 0)
//		executePB(res_lst, b);
//	else if (ft_strcmp(line, "ra") == 0)
//		executeRA(res_lst);
//	else if (ft_strcmp(line, "rb") == 0)
//		executeRB(b);
//	else if (ft_strcmp(line, "rr") == 0)
//		executeRR(res_lst, b, 0, 0);
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

//int 	get_data(t_stack *a_stack, t_stack *b_stack, int flag)
//{
//	int j;
//
//	j = ((flag & COLOR_FLAG) ? 1 : 0) + ((flag & VISUALIZE_FLAG) ? 1 : 0);
//	j = (flag & READFILE_FLAG) ? 0 : j;
//	a_stack->flag = flag;
//	b_stack->flag = flag;
//	b_stack->length = 0;
//}
//
//int 	execute(int ac, char **av, unsigned flag)
//{
//	t_list_arr	*res_lst;
//	t_list_arr	*b;
//	char		*line;
//	t_stack		b_stack;
//	t_stack		a_stack;
//
//	res_lst = nb_lstnew();
//	b = nb_lstnew();
//	if (!save_stack(ac, av, res_lst, flag))
//		return (0);
//	get_data(&a_stack, &b_stack, flag);
//	fill_data(res_lst, ac, &a_stack, j);
//	while (get_next_line(0, &line) > 0)
//	{
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

//int		main(int ac, char **av)
//{
//	char		*line;
//	int			fd;
//	unsigned	res;
//	char 		**sp_line;
//	char        *tmp;
//
//	if ((fd = read_input(ac, av, &res)) == -2)
//		return (write(2, "Error\n", 6));
//	if (!(res & READFILE_FLAG))
//		execute(ac, av, res);
//	else
//	{
//		while (get_next_line(fd, &line) > 0)
//		{
//			if (!*line)
//				break;
//			sp_line = ft_strsplit(tmp = ft_strjoin("0 ", line), ' ');
//			ac = count_wrds(sp_line);
//			execute(ac, av, res);
//			free(tmp);
//			free(line);
//			free(sp_line);
//		}
//	}
//}
