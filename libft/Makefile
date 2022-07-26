# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: styes <styes@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 20:58:29 by styes             #+#    #+#              #
#    Updated: 2022/07/26 23:50:00 by styes            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC        = gcc
RM        = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c\

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "\\n\033[34;1m LIBFT CREATED \033[0m \\n"
	

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@echo "\\n\033[32;1m LIBFT OBJECT FILE DELETED \033[0m \\n"
	

fclean:    clean
	@${RM} ${NAME}
	@echo "\\n\033[32;1m LIBFT DELETED \033[0m \\n"
	

re:        fclean all
