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
# include "execute.h"

#include "get_next_line.h"

typedef struct		s_stack
{
	int				max;
	int				min;
	int				mdn;
	int				length;
}					t_stack;

int		create_elem(void *str, size_t len, t_list **lst);
int		save_stack(int ac, char **av, t_list_arr *res_lst);
int		lst_length(t_list *lst);
int		lst_sorted_dec(t_list *lst);
int		lst_sorted_ac(t_list *lst);
t_list_arr	*nb_list_at(t_list_arr *begin_list, unsigned int nbr);
t_list_arr	*create_nb_elem(int nb, t_list_arr **lst);
t_list_arr  *nb_lstnew();
int		nb_lst_length(t_list_arr *lst);
void	nb_push_back(t_list_arr **start, t_list_arr *new);


#endif