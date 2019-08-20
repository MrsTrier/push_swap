.PHONY: all clean fclean re push_swap checker reclean

NAME1 = checker
NAME2 = push_swap
RMS = /bin/rm -rf
LIBFT = src/libft/
SHARED = src/shared/
PUSH_SWAP_F = src/push_swap/
CHECKER_F = src/checker/
CHECKER = $(NAME1)
PUSH_SWAP = $(NAME2)

all:
	@make -C $(LIBFT)
	@make -C $(SHARED)
	@make -C $(PUSH_SWAP_F)
	@make -C $(CHECKER_F)

$(NAME1):
	@if [ -e $(CHECKER) ]; then \
		make silent_re -C $(CHECKER_F); \
	else \
		make -C $(CHECKER_F); \
	fi

$(NAME2):
	@if [ -e $(PUSH_SWAP) ]; then \
		make silent_re -C $(PUSH_SWAP_F); \
	else \
		make -C $(PUSH_SWAP_F); \
	fi

clean:
	@echo "$(LIBFT) folder:\c"
	@make clean -C $(LIBFT)
	@echo "$(SHARED) folder:\c"
	@make clean -C $(SHARED)
	@echo "$(PUSH_SWAP_F) folder:\c"
	@make clean -C $(PUSH_SWAP_F)
	@echo "$(CHECKER_F) folder:\c"
	@make clean -C $(CHECKER_F)

fclean: clean
	@#echo "$(LIBFT) folder:\c"
	@make fclean -C $(LIBFT)
	@#echo "$(SHARED) folder:\c"
	@make fclean -C $(SHARED)
	@#echo "$(PUSH_SWAP_F) folder:\c"
	@make fclean -C $(PUSH_SWAP_F)
	@#echo "$(CHECKER_F) folder:\c"
	@make fclean -C $(CHECKER_F)
	@$(RMS) $(PUSH_SWAP) $(CHECKER)

re: fclean all

reclean: re
	@make clean