#SILENCE THE WRITING..
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
	lis.c\
	array_manipulation.c\
	lis_construction.c\
	best_element.c\

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

clean:
	make clean -C libft
	rm -f push_swap

fclean: clean
	make fclean -C libft

re: clean All
.PHONY: clean fclean re 