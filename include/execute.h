#ifndef EXECUTE_H
# define EXECUTE_H

#include "libft.h"
#include "push_swap.h"

int			executeSA(t_list_arr **a, t_list_arr **b, t_stack *a_data, int ss);
int			executeSB(t_list_arr **a, t_list_arr **b, t_stack *a_data, int ss);
void		executePA(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void		executePB(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRB(t_list_arr **a, t_list_arr **b, int rr, t_stack *a_stack);
void		executeRA(t_list_arr **a, t_list_arr **b, int rr, t_stack *a_stack);
void		executeSS(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRR(t_list_arr **a, t_list_arr **b, t_stack *a_data, t_stack *b_data);
void		executeRRA(t_list_arr **a, t_list_arr **b, t_stack *a_data, int rrr);
void		executeRRB(t_list_arr **a, t_list_arr **b, t_stack *b_data, int rrr);
void		executeRRR(t_list_arr **a, t_stack *a_data, t_list_arr **b, t_stack *b_data);

t_list_arr	*nb_list_at(t_list_arr *begin_list, unsigned int nbr);
int			*lst_to_arr(t_list_arr *lst, int ac);
void		heap_sort(int max, int **stack);

#endif