#include <unistd.h>
#include <libft.h>
#include "checker.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	buf[1];
	char	*comand;
	char	*str;
	t_list	*instruction;
	int		i;
	char 	prev;

	i = 0;
	prev = 'v';
	while (read(0, buf, sizeof(buf))>0)
	{
		if ((buf[0] < 'a' || buf[0] > 'z') && buf[0] != '\n')
			return (-1);
		if (buf[0] >= 'a' && buf[0] <= 'z')
		{
			if (!i) {
				comand = (char *) malloc(sizeof(char) * 2);
				comand[i] = buf[0];
				comand[++i] = '\0';
			} else {
				i = 0;
				str = (char *) malloc(sizeof(char) * 2);
				str[i] = buf[0];
				str[++i] = '\0';
				ft_strappend(comand, str);
			}
		}
		if (buf[0] == '\n' && prev != '\n')
		{
			instruction = ft_lstnew(NULL, 0);
			create_node(comand, ft_strlen(comand) + 1, &instruction);
			ft_printf("%s\n", instruction->content);
		}
		else
			break;
		prev = buf[0];
	}
}