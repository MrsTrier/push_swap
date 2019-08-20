.PHONY: all clean fclean re silent_clean silent_fclean silent_re

HFILES = ../../include

NAME = checker

RM = /bin/rm -rfv
RMS = /bin/rm -rf
SHARED = ../shared/
SHARED_F = shared.a
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = checker.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(SHARED)$(SHARED_F) ]; then \
		make silent_re -C $(SHARED); \
	fi
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make silent_re -C $(LIBFT_F); \
	fi
	@if [ -e $(SHARED)$(SHARED_F) -a -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES) -I$(HFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(SHARED)$(SHARED_F) $(LIBFT_F)$(LIBFT) -o $(NAME); \
		cp $(NAME) $(OUT); \
		echo "$(NAME) compiled"; \
	else \
		echo "something wrong with $(LIBFT) or/and SHARED_F) libraries"; \
	fi

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