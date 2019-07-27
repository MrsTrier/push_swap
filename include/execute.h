#ifndef EXECUTE_H
# define EXECUTE_H

#include "libft.h"

int		executeSAB(t_list_arr **res_lst, int elemNum);
void	executePA(t_list_arr **a, t_list_arr **b);
void	executePB(t_list_arr **a, t_list_arr **b);
void	executeRAB(t_list_arr **a);
void	executeSSRR(t_list_arr **a, t_list_arr **b, int a_length, int b_length);
void	executeRRAB(t_list_arr **res_lst, int a_length);
void	executeRRR(t_list_arr **res_lst, int a_length, t_list_arr **b, int b_length);



//int		executeSAB(t_list **res_lst, int elemNum);
//void	executeSSRR(t_list **a, t_list **b, int a_length, int b_length);
//void	executePA(t_list **a, t_list **b);
//void	executePB(t_list **a, t_list **b);
//void	executeRAB(t_list **a);
//void	executeRRAB(t_list **res_lst, int a_length);
//void	executeRRR(t_list **res_lst, int a_length, t_list **b, int b_length);



#endif