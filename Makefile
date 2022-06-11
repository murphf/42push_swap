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

EXEC= push_swap

#color codes
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_PURPLE=\033[0;35m
YELLOW_H=\x1b[45m
COLOR_END=\033[0m

All: $(EXEC)

push_swap: $(SRC)
	$(CC) $(SRC) -o $@

clean:
	rm -f push_swap

fclean: clean

re: clean All

.PHONY: clean fclean re 