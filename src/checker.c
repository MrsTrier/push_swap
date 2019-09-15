#include "checker.h"
#include <stdio.h>
#include <limits.h>

void	execute_rest(t_list_arr **res_lst, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	if (ft_strcmp(b_data->cmnd[0], "rra") == 0 && a_data->length > 1)
		executeRRA(res_lst, b, a_data, 1);
	else if (ft_strcmp(b_data->cmnd[0], "rrb") == 0 && b_data->length > 1)
		executeRRB(res_lst, b, b_data, 1);
	else if (ft_strcmp(b_data->cmnd[0], "rrr") == 0 && a_data->length > 1 && b_data->length > 1)
		executeRRR(res_lst, a_data, b, b_data);
}

int 	get_data(t_stack *a_stack, t_stack *b_stack, unsigned flag)
{
	int j;

	j = ((flag & COLOR_FLAG) ? 1 : 0) + ((flag & VISUALIZE_FLAG) ? 1 : 0);
	j = (flag & READFILE_FLAG) ? 0 : j;
	a_stack->flag = flag;
	b_stack->flag = flag;
	b_stack->length = 0;
	return (0);
}

void	execute_comand(t_list_arr **res_lst, t_list_arr **b, t_stack *a_data, t_stack *b_data)
{
	if ((ft_strcmp(b_data->cmnd[0], "sa") == 0) && a_data->length >= 2)
		executeSA(res_lst, b, a_data, 0);
	else if ((ft_strcmp(b_data->cmnd[0], "sb") == 0) && b_data->length >= 2)
		executeSB(res_lst, b, a_data, 0);
	else if (ft_strcmp(b_data->cmnd[0], "ss") == 0 && a_data->length >= 2 && b_data->length >= 2)
		executeSS(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "pa") == 0 && b_data->length > 0)
		executePA(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "pb") == 0 && a_data->length > 0)
		executePB(res_lst, b, a_data, b_data);
	else if (ft_strcmp(b_data->cmnd[0], "ra") == 0 && a_data->length > 1)
		executeRA(res_lst, b, 0, a_data);
	else if (ft_strcmp(b_data->cmnd[0], "rb") == 0 && a_data->length > 1)
		executeRB(res_lst, b, 0, a_data);
	else if (ft_strcmp(b_data->cmnd[0], "rr") == 0 && b_data->length > 1 && a_data->length > 1)
		executeRR(res_lst, b, a_data, b_data);
	else
		execute_rest(res_lst, b, a_data, b_data);
}

int		manage_comands(t_list_arr **res_lst, t_list_arr **b, t_stack *a_stack, t_stack *b_stack)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!*line)
			break;
		if (!valid(line))
		{
			free(line);
			return (write(2, "Error\n", 6));
		}
		(b_stack->cmnd)[0] = ft_strdup(line);
		execute_comand(res_lst, b, a_stack, b_stack);
		free(line);
		free(*b_stack->cmnd);
	}
	return (1);
}

void	ft_lstiter_int(t_list_arr *a)
{
	t_list_arr *new_item;

	if (!a)
		return ;
	new_item = a;
	while (new_item)
	{
		ft_printf("%d", new_item->content);
		new_item = new_item->next;
	}
}

int 	execute(int ac, char **av, unsigned flag)
{
	t_stack		b_stack;
	t_stack		a_stack;
	t_list_arr	*res_lst;
	t_list_arr	*b;

	res_lst = nb_lstnew();
	b = nb_lstnew();
	get_data(&a_stack, &b_stack, flag);
	if ((save_stack(ac, av, res_lst, (int*)&flag)) == 6)
		return (0);
	fill_data(res_lst, ac - 1 - (int)flag, &a_stack, &b_stack);
//	write(1, "Please, enter instructions into the standard input and press 'enter' twice\n", 75);
	manage_comands(&res_lst, &b, &a_stack, &b_stack);
	if ((lst_sorted_ac(res_lst, 0, a_stack.length)) || b_stack.length != 0)
		return (write(2, "KO\n", 3));
	else
	{
//		ft_lstiter_int(res_lst);
		return (write(1, "OK\n", 3));
	}
//	while (res_lst->next)
//	{
//		ft_printf("%d\n", res_lst->content);
//		res_lst = res_lst->next;
//	}
//	ft_printf("%d\n", flag);
//	ft_printf("%d\n", res_lst->content);
}

int		main(int ac, char **av)
{
	char		*line;
	int			fd;
	unsigned	res;
	char 		**sp_line;
	char        *tmp;

	if ((fd = read_input(ac, av, &res)) == -2)
		return (write(2, "Error\n", 6));
	if (!(res & READFILE_FLAG))
		execute(ac, av, res);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!*line)
				break;
			sp_line = ft_strsplit(tmp = ft_strjoin("0 ", line), ' ');
			ac = count_wrds(sp_line);
			execute(ac, sp_line, res);
			free(tmp);
			free(line);
			free(sp_line);
		}
	}
}

//pb
//pb
//pb
//pb
//rr
//ra
//rrr
//pa
//pa
//pa