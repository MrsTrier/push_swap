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

int		lst_length(t_list *lst);
int		create_elem(void *str, size_t len, t_list **lst);
int		lst_sorted(t_list *lst);
int 	valid(char *line);
void	put_string(t_list *elem);
int		save_stack(int ac, char **av, t_list *res_lst);


#endif