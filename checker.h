#ifndef FT_CHECKER_H
# define FT_CHECKER_H

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

void	lst_delete_last(t_list **start);
int		lst_length(t_list *lst);
int		create_elem(void *str, size_t len, t_list **lst);
int		lst_sorted(t_list *lst, int (*f)(int new_item, int next_item));
int 	f(int cur, int next);

#endif