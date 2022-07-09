#SILENCE THE WRITING in in libft makefile..
#ADD A LOADING BAR..
CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRC= main.c\
	annexe_functions.c\
	linked_list_manipulation.c\
	moves_writer.c\
	ops.c\
	parser_stuff.c\
	sorting_algos.c\
	insert_sort.c\
	print_stacks.c\
	array_manipulation.c\
	lis_construction.c\
	moves_counters.c\
	push_best_element_3.c\
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
	make -C libft
	$(CC) $(SRC) libft/libft.a -o $@

clean_lib:
	make clean -C libft

clean: clean_lib
	rm -f push_swap

fclean: clean
	make fclean -C libft

re: clean All
.PHONY: clean clean_lib fclean re 