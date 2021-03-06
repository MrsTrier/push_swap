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

void		print_stack_b(t_stack *a_data, int *i, t_arr **b, t_arr **pr_b)
{
	while ((a_data->a_is_full) ? (*i < a_data->length) : (*pr_b != NULL))
	{
		ft_printf("%5d |   %-22s |   %-22d \n", *i, "(null)",
				(a_data->a_is_full) ? 0 : (*pr_b)->content);
		*pr_b = (a_data->a_is_full) ? *b : (*pr_b)->next;
		(*i)++;
	}
}

int			print_stack_b_a(t_stack *a_data, t_arr **pr_a,
									t_arr **b, t_arr **pr_b)
{
	int		i;

	i = 0;
	while ((a_data->a_is_full == false) && (*pr_a != NULL) && (*pr_b != NULL))
	{
		(a_data->a_is_full) ?
		(ft_printf("%5d |   %-22d |   %-22s \n", i, (*pr_a)->content, NULL)) :
		(ft_printf("%5d |   %-22d |   %-22d \n", i,
					(*pr_a)->content, (*pr_b)->content));
		(*pr_a) = (*pr_a)->next;
		(*pr_b) = (a_data->a_is_full) ? *b : (*pr_b)->next;
		i++;
	}
	return (i);
}

void		visualize(t_arr **a, t_arr **b, char *cmnd, t_stack *a_data)
{
	t_arr	*pr_a;
	t_arr	*pr_b;
	int		i;
	int		color;

	color = (a_data->flag & COLOR_FLAG) ? 1 : 0;
	i = 0;
	pr_a = *a;
	pr_b = *b;
	ft_printf("    № |   A %-20s|   B %-20s\n", "STACK", "STACK");
	ft_printf("- - - - - - - - - - - - - - - - - - - - - - - "
		"- - - - - - - -\n");
	i += print_stack_b_a(a_data, &pr_a, b, &pr_b);
	while (pr_a)
	{
		ft_printf("%5d |   %-22d |   %-22s \n", i, pr_a->content, "(null)");
		pr_a = pr_a->next;
		i++;
	}
	print_stack_b(a_data, &i, b, &pr_b);
	if (color)
		ft_printf("\033[0;35m Last command \033[0m%s\n", cmnd);
	ft_printf("============================================"
		"=================\n");
}

int			valid(char *line)
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
