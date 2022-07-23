#SILENCE THE WRITING in in libft makefile..
#ADD A LOADING BAR..
CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= main.c\
	linked_list_manipulation.c\
	moves_writer0.c\
	moves_writer1.c\
	moves_writer2.c\
	stack_ops0.c\
	stack_ops1.c\
	algebra.c\
	parsing.c\
	errors_check.c\
	print_stacks.c\
	array_manipulation.c\
	moves_counters.c\
	best_element_algo.c\
	best_elements_annex.c\
	push_best_element.c\
	positions_extremes.c\
	lis_constructor.c\

SRC_b= checker.c\
	checker_utils.c\
	parsing.c\
	linked_list_manipulation.c\
	errors_check.c\
	print_stacks.c\
	stack_ops0.c\
	stack_ops1.c\
	algebra.c\

EXEC= push_swap
bonus= checker

#color codes
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_PURPLE=\033[0;35m
YELLOW_H=\x1b[45m
COLOR_END=\033[0m

All: $(EXEC)

push_swap: $(SRC) push_swap.h
	@make -C libft
	@echo "\033[0;34mcreating push_swap\033[0m"
	@$(CC) $(SRC) libft/libft.a -o $@

bonus: $(SRC_b) push_swap.h
	@make -C libft
	$(CC) $(SRC_b) libft/libft.a -o checker

clean:
	@make clean -C libft
	@echo "\033[0;32mdeleting push_swap...\033[0m"
	@rm -f push_swap
	@rm -f checker

fclean: clean
	@make fclean -C libft

re: clean All

.PHONY: clean fclean re 