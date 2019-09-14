#include "push_swap.h"
#include "execute.h"

int     find_min(t_list_arr *res_lst)
{
	int			min;
	t_list_arr	*new_item;

	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	min = new_item->content;
	while (new_item->next)
	{
		if (min > new_item->next->content)
			min = new_item->next->content;
		new_item = new_item->next;
	}
	return (min);
}

int     find_max(t_list_arr	*res_lst)
{
	int			max;
	t_list_arr	*new_item;

	if (!res_lst)
		return (write(2, "Error\n", 6));
	new_item = res_lst;
	max = new_item->content;
	while (new_item->next)
	{
		if (max < new_item->next->content)
			max = new_item->next->content;
		new_item = new_item->next;
	}
	return (max);
}

int 	read_input(int ac, char **av, unsigned *res)
{
	int			fd;
	int			i;

	fd = -1;
	i = 1;
	*res = 0;
	while (ac > 2 ? i < 3 : i < 2)
	{
		if (!is_int(av[i]))
		{
			if (ft_strcmp("-c", av[i]) == 0)
				*res |= COLOR_FLAG;
			else if (ft_strcmp("-v", av[i]) == 0)
				*res |= VISUALIZE_FLAG;
			else if ((fd = open(av[i], O_RDONLY)) != -1)
				*res |= READFILE_FLAG;
			else
				return (-2);
		}
		i++;
	}
	return (fd);
}

int 	count_wrds(char **sp_line)
{
	int 	wrds;

	wrds = 1;
	while (sp_line[wrds] != NULL)
		wrds++;
	return (wrds);
}

void	fill_data(t_list_arr *a, int i, t_stack *a_data, t_stack * b_data)
{
	int			*arr;

	arr = lst_to_arr(a, i); // ac- 1-i
	a_data->length = i;
	a_data->min = find_min(a);
	a_data->max = find_max(a);
	heap_sort(i, &arr);
	a_data->mdn = arr[(a_data->length / 2)];
	a_data->cmnd = (char**)malloc(sizeof(a_data->cmnd) * 100); //выделить память на массив
//	(*a_data->cmnd) = "try\n";
//	*(a_data->cmnd + 1) = "try2\n";
	b_data->cmnd = (char**)malloc(sizeof(b_data->cmnd) * 100);
	a_data->pr = (a_data->cmnd);
	b_data->pr = (b_data->cmnd);
//	a_data->cmnd++;
	free(arr);
}