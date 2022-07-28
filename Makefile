#make checker should work..
CC=gcc
CFLAGS=-Wall -Wextra -Werror

#the four main folders / areas of the code
AN=annex_functions/
BEST=best_element/
CHEC=checker_/
MV=moves/

SRC= main.c\
	$(AN)linked_list_manipulation.c\
	$(AN)algebra.c\
	$(AN)parsing.c\
	$(AN)errors_check.c\
	$(AN)print_stacks.c\
	$(AN)array_manipulation.c\
	$(AN)positions_extremes.c\
	$(MV)moves_writer0.c\
	$(MV)moves_writer1.c\
	$(MV)moves_writer2.c\
	$(MV)stack_ops0.c\
	$(MV)stack_ops1.c\
	$(BEST)moves_counters.c\
	$(BEST)best_element_algo.c\
	$(BEST)best_elements_annex.c\
	$(BEST)push_best_element.c\
	$(BEST)lis_constructor.c\

SRC_b= $(CHEC)checker.c\
	$(CHEC)checker_utils.c\
	$(AN)parsing.c\
	$(AN)linked_list_manipulation.c\
	$(AN)errors_check.c\
	$(AN)print_stacks.c\
	$(AN)algebra.c\
	$(MV)stack_ops0.c\
	$(MV)stack_ops1.c\

#COLOR CODES
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_PURPLE=\033[0;35m
YELLOW_H=\x1b[45m
COLOR_END=\033[0m

All: push_swap

push_swap: $(SRC) ./includes/push_swap.h
	@make -C libft
	@$(CC) $(SRC) libft/libft.a -o $@
	@echo "\\n\033[34;1m PUSH_SWAP CREATED \033[0m \\n"

bonus checker: $(SRC_b) ./includes/push_swap.h
	@make -C libft
	@$(CC) $(SRC_b) libft/libft.a -o checker
	@echo "\\n\033[34;1m CHECKER CREATED \033[0m \\n"
clean:
	@make clean -C libft
	@rm -f push_swap
	@echo "\\n\033[32;1m PUSH_SWAP DELETED \033[0m\\n"
	@rm -f checker
	@echo "\\n\033[32;1m CHECKER DELETED \033[0m\\n"
	
fclean:
	@make fclean -C libft
	@rm -f push_swap
	@echo "\\n\033[32;1m PUSH_SWAP DELETED \033[0m \\n"
	@rm -f checker
	@echo "\\n\033[32;1m CHECKER DELETED \033[0m\\n"

re: clean All

.PHONY: clean fclean re 