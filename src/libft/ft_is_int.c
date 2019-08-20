#include "libft.h"

t_bool	is_int(const char *str)
{
	unsigned long	result;
	unsigned long	border;
	int				i;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (LLONG_MAX / 10);
	i = 0;
	while (str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && ++digits)
	{
		if (((result > border || (result == border && (str[i] - '0') > 7))
			 && sign == 1)
			|| ((result > border || (result == border && (str[i] - '0') > 8))
				&& sign == -1))
			return (false);
		result = result * 10 + (str[i++] - '0');
	}
	return (!str[i] && digits);
}
