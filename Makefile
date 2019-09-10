NAME = push_swap
SRC_DIR = ./src
SRC = src/checker/checker.c src/shared/execute_rest.c src/shared/heap_sort.c src/shared/lst_arr_functions.c src/shared/lst_execute.c src/shared/nb_execute.c src/shared/read_input.c src/shared/validation.c src/push_swap/nb_lst.c src/push_swap/push_swap.c
SRC_ps = src/push_swap/nb_lst.c src/push_swap/push_swap.c src/shared/execute_rest.c src/shared/heap_sort.c src/shared/lst_arr_functions.c src/shared/lst_execute.c src/shared/nb_execute.c src/shared/read_input.c src/shared/validation.c
SRC_ch = src/checker.c src/shared/execute_rest.c src/shared/heap_sort.c src/shared/lst_arr_functions.c src/shared/lst_execute.c src/shared/nb_execute.c src/shared/read_input.c src/shared/validation.c

OBJ_DIR = ./objs
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_ps = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_ps))
OBJ_ch = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_ch))
INC_DIR	:= include
LIBFT_DIR = src/libft
LIBFT_INC_DIR = ./include
PRINTF_DIR = src/printf
PRINTF_INC_DIR = ../../include
LIBFT_INC_DIR = ../../include

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	echo $INC_DIR
	@gcc -Wall -Werror -Wextra -I$(LIBFT_INC_DIR) -I$(INC_DIR) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@echo "$(NAME) compiling... \c";
	@gcc -Wall -Werror -Wextra -L $(LIBFT_DIR) -L $(PRINTF_DIR) -o $(NAME) $(OBJ_ps) -I$(LIBFT_INC_DIR) -I$(INC_DIR)
#	@gcc -Wall -Werror -Wextra  -L $(LIBFT_DIR) $(PRINTF_DIR) -l -o checker $(OBJ_ch) -I$(LIBFT_INC_DIR) -I$(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@make -C $(LIBFT_DIR) fclean

re: fclean all
