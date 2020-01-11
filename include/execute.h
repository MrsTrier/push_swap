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

int			execute_sa(t_arr **a, t_arr **b, t_stack *a_data, int ss);
int			execute_sb(t_arr **a, t_arr **b, t_stack *b_data, int ss);
void		execute_pa(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		execute_pb(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		execute_rb(t_arr **a, t_arr **b, int rr, t_stack *b_data);
void		execute_ra(t_arr **a, t_arr **b, int rr, t_stack *a_data);
void		execute_ss(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		execute_rr(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
void		execute_rra(t_arr **a, t_arr **b, t_stack *a_data, int rrr);
void		execute_rrb(t_arr **a, t_arr **b, t_stack *b_data, int rrr);
void		execute_rrr(t_arr **a, t_stack *a_data, t_arr **b, t_stack *b_data);

t_arr		*nb_list_at(t_arr *begin_list, unsigned int nbr);
int			*lst_to_arr(t_arr *lst, int ac);
void		heap_sort(int max, int **stack);

#endif