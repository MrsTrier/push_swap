/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:02:12 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 20:02:14 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

#include "libft.h"
#include "push_swap.h"

int			executeSA(t_arr **a, t_arr **b, t_stack *a_data, int ss);
int			executeSB(t_arr **a, t_arr **b, t_stack *a_data, int ss);
void		executePA(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		executePB(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRB(t_arr **a, t_arr **b, int rr, t_stack *a_stack);
void		executeRA(t_arr **a, t_arr **b, int rr, t_stack *a_stack);
void		executeSS(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRR(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRRA(t_arr **a, t_arr **b, t_stack *a_data, int rrr);
void		executeRRB(t_arr **a, t_arr **b, t_stack *b_data, int rrr);
void		executeRRR(t_arr **a, t_stack *a_data, t_arr **b, t_stack *b_data);

t_arr	*nb_list_at(t_arr *begin_list, unsigned int nbr);
int			*lst_to_arr(t_arr *lst, int ac);
void		heap_sort(int max, int **stack);

#endif