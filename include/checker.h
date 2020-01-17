/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:59:41 by mcanhand          #+#    #+#             */
/*   Updated: 2020/01/17 13:59:41 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "ft_printf.h"
# include "conversions.h"
# include "large_arythmetics.h"
# include "float_to_str.h"
# include "floats.h"
# include "execute.h"

# include "get_next_line.h"

int		lst_sorted_ac(t_arr *lst, int elem, int l_elem);
int		valid(char *line);
int		read_input(int ac, char **av, unsigned *res);
int		count_wrds(char **sp_line);
void	fill_data(t_arr *a, int i, t_stack *a_data, t_stack *b_data);

#endif
