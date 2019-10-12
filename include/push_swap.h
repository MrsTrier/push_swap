/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:02:06 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 20:02:08 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
#include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"
# include "conversions.h"
# include "large_arythmetics.h"
# include "float_to_str.h"
# include "floats.h"
//# include "execute.h"

#include "get_next_line.h"


# define COLOR_FLAG 1U
# define READFILE_FLAG 2U
# define VISUALIZE_FLAG 4U

#define RRA "rra : the last element in stack a become the first one"
#define RRB "rrb : the last element in stack b become the first one"
#define RRR "rrr : rra and rrb were executed at the same time"
#define RA "ra : first element in a stack A become the last one"
#define RB "rb : first element in a stack B become the last one"
#define PA "pa : first element at the top of b become the top of a"
#define PB "pb : first element at the top of a become the top of b"
#define SA "sa : the first 2 elements at the top of a stack a were swaped"
#define SB "sb : the first 2 elements at the top of a stack b were swaped"
#define RR "rr : ra and rb were executed at the same time"
#define SS "ss : sa and sb were executed at the same time"

typedef struct		s_stack
{
	int				max;
	int				min;
	int				mdn;
	int				length;
	char 			**cmnd;
	char 			**pr;
    char 			**first_elem;
    unsigned		flag;

}					t_stack;

typedef struct		s_cmnd
{
	int				best;
	int				place;
	int				b;
	int				a;
	int 			c;
}					t_cmnd;

int			save_stack(int ac, char **av, t_arr *res_lst, int *flag);
int			lst_length(t_list *lst);
int			lst_sorted_dec(t_arr *lst);
int		    lst_sorted_ac(t_arr *lst, int elem, int l_elem);
t_arr		*create_nb_elem(int nb, t_arr **lst, int i);
t_arr		*nb_lstnew();
t_arr		*ft_list_elem(t_arr *begin_list, unsigned int nbr);
int			nb_lst_length(t_arr *lst);
void		nb_push_back(t_arr **start, int nb);
void		visualize(t_arr **a, t_arr **b, char *cmnd, int color);
void		free_lst_arr(t_arr *lst);
int			detect_index(t_arr **a, int place);
int			read_input(int ac, char **av, unsigned *res);
int 		count_wrds(char **sp_line);
void		fill_data(t_arr *a, int i, t_stack *a_data, t_stack *b_data);
int			how_much_sorted(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
int			optimazationRRR(t_arr **a, t_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data);
int			optimazationRR(t_arr **a, t_arr **b, t_cmnd cmnd, t_stack *a_data, t_stack *b_data);
int			switch_in_b(t_arr **a, t_arr **b, t_stack *b_data, int nb);
int			switch_in_a(t_arr **a, t_arr **b, t_stack *a_data, int nb);
int			easy(t_arr **a, t_stack *a_data);
int			mk_easy_sort(t_arr **a, t_arr **b, t_stack *a_data);
int			free_a(t_arr **a, t_arr **b, t_stack *a_data, t_stack *b_data);
int			min_is(int up, int bottom);
int			calculate_comands(t_arr **a, t_cmnd *cmnd, int b, int a_length);
void		free_arr(char **arr);
//void		free_int_arr(int **arr, int ac);
void        merge_comands(t_stack *b_data, t_stack *a_data);



#endif