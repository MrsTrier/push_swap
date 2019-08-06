#ifndef EXECUTE_H
# define EXECUTE_H

#include "libft.h"
#include "push_swap.h"

int		executeSAB(t_list_arr **a, t_list_arr **b, int elemNum, int a_or_b, int ss);
void	executePA(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void	executePB(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void	executeRAB(t_list_arr **a, t_list_arr **b, int a_or_b, int ss);
void	executeSSRR(t_list_arr **a, t_list_arr **b, t_stack *a_data, int rr);
void	executeRRA(t_list_arr **a, t_list_arr **b, int length);
void	executeRRB(t_list_arr **a, t_list_arr **b, int length);
void	executeRRR(t_list_arr **a, int a_length, t_list_arr **b, int b_length);

#endif