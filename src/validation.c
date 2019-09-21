/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:46:05 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/21 16:16:33 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "checker.h"
#include "push_swap.h"

void	visualize(t_arr **a, t_arr **b, char *cmnd, int color)
{
	t_arr	*pr_a;
	t_arr	*pr_b;
	int		i;

	i = 0;
	pr_a = *a;
	pr_b = *b;
	ft_printf("    № |   A %-20s|   B %-20s\n", "STACK", "STACK");
	ft_printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	while (pr_a && pr_b)
	{
		ft_printf("%5d |   %-22d |   %-22d \n", i, pr_a->content, pr_b->content);
		pr_a = pr_a->next;
		pr_b = pr_b->next;
		i++;
	}
	while (pr_a)
	{
		ft_printf("%5d |   %-22d |   %-22s \n", i, pr_a->content, "(null)");
		pr_a = pr_a->next;
		i++;
	}
	while (pr_b)
	{
		ft_printf("%5d |   %-22s |   %-22d \n", i, "(null)", pr_b->content);
		pr_b = pr_b->next;
		i++;
	}
	if (color)
		ft_printf("\033[0;35m Last command \033[0m%s\n", cmnd);
	ft_printf("=============================================================\n");
}

int		valid(char *line)
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

int		*any_double(char **av, int ac, int flag)
{
	int		i;
	int		j;
	int		*arr;

	i = 1 + flag;
	j = 1 + flag;
	arr = (int *)malloc(sizeof(int) * (ac - 1 - flag));
	while (i < ac)
	{
		if (!is_int(av[i]))
			return (NULL);
		arr[i - 1 - flag] = ft_atoi(av[i]);
		while (j < ac - flag)
		{
			if ((ft_atoi(av[j]) == arr[i - 1 - flag]) && (j != i))
				return (NULL);
			j++;
		}
		i++;
		j = 1 + flag;
	}
	return (arr);
}

int		save_stack(int ac, char **av, t_arr *res_lst, int *flag)
{
	int			i;
	int			j;
	t_arr		*stack;
	int			*arr;

	j = ((*flag & COLOR_FLAG) ? 1 : 0) + ((*flag & VISUALIZE_FLAG) ? 1 : 0);
	j = (*flag & READFILE_FLAG) ? 0 : j;
	i = 1;
	stack = res_lst;
	if (ac < 2)
		return (6);
	if ((arr = any_double(av, ac, j)) == NULL)
		return (6);
	while (i < ac - j)
	{
		create_nb_elem(arr[i - 1], &stack, i);
		i++;
	}
	free(arr);
	*flag = j;
	return (j);
}
