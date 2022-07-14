#SILENCE THE WRITING in in libft makefile..
#ADD A LOADING BAR..
CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= main.c\
	linked_list_manipulation.c\
	moves_writer.c\
	ops.c\
	parsing.c\
	errors_check.c\
	sorting_algos.c\
	insert_sort.c\
	print_stacks.c\
	array_manipulation.c\
	lis_construction.c\
	moves_counters.c\
	push_best_element.c\
	best_elements_annex.c\
	quicksort_arr.c\
	positions_extremes.c\
	c_lis_constructor.c\

EXEC= push_swap

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

clean:
	@make clean -C libft
	@echo "\033[0;32mdeleting push_swap...\033[0m"
	@rm -f push_swap

fclean: clean
	@make fclean -C libft

re: clean All

.PHONY: clean fclean re 