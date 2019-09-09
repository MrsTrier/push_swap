.PHONY: all clean fclean re silent_clean silent_fclean silent_re

HFILES = ../../include
NAME = shared.a
RM = /bin/rm -rfv
RMS = /bin/rm -rf
CFILES = execute_rest.c lst_arr_functions.c nb_execute.c read_input.c validation.c heap_sort.c lst_execute.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(NAME) compiling... \c"
	@gcc -Wall -Wextra -Werror -c $(CFILES) -I$(HFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo "$(NAME) created"

clean:
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean all