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
int		save_stack(int ac, char **av, t_list *res_lst);
int		lst_length(t_list *lst);
int		lst_sorted_dec(t_list *lst);
int		lst_sorted_ac(t_list *lst);

#endif