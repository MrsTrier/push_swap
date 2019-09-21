NAME1 = push_swap

NAME2 = checker

SRCDIR = ./src/

OBJDIR = $(SRCDIR)obj/

LFTDIR = $(SRCDIR)libft/

LFT = $(LFTDIR)libft.a

LIBFT_INC_DIR = ./include

LFTPRINTFDIR = $(SRCDIR)printf/

LFTPRINTF = $(LFTPRINTFDIR)libftprintf.a

SRCS1 = $(addprefix $(SRCDIR), nb_lst.c push_swap.c execute_rest.c heap_sort.c lst_arr_functions.c lst_execute.c nb_execute.c read_input.c validation.c supportive_functions.c optimazation_functions.c result_comands.c free_functions.c)

SRCS2 = $(addprefix $(SRCDIR), checker.c execute_rest.c heap_sort.c lst_arr_functions.c lst_execute.c nb_execute.c read_input.c validation.c)

OBJ1 = $(SRCS1:%.c=$(OBJDIR)%.o)

OBJ2 = $(SRCS2:%.c=$(OBJDIR)%.o)

CC = gcc -Wall -Werror -Wextra

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME1) done!"

$(NAME2): $(OBJ2) $(LFT) $(LFTPRINTF)
	@$(CC) -L$(LFTDIR) -lft -L$(LFTPRINTFDIR) -lftprintf $^ -o $@
	@echo "$(NAME2) done!"

$(LFT):
	@$(MAKE) -C $(LFTDIR)
	@$(MAKE) -C $(LFTDIR) clean

$(LFTPRINTF):
	@$(MAKE) -C $(LFTPRINTFDIR)
	@$(MAKE) -C $(LFTPRINTFDIR) clean

$(OBJDIR)%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) -I./include -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LFTDIR) fclean
	@$(MAKE) -C $(LFTPRINTFDIR) fclean

fclean: clean
	@rm -f $(NAME1) $(NAME2)

re: fclean all
