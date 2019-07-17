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

int		create_elem(void *str, size_t len, t_list **lst);
int		save_stack(int ac, char **av, t_list *res_lst);


#endif