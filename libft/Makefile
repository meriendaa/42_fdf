# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:37:26 by tmerida-          #+#    #+#              #
#    Updated: 2022/02/04 21:37:29 by tmerida-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c\
			ft_memset.c\
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c\
			ft_bzero.c\
			ft_atoi.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_strlcpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strmapi.c\
			ft_strnstr.c\
			ft_itoa.c\
			ft_strtrim.c\
			ft_split.c

OBJ = $(SRC:.c=.o)

CC = gcc -I./includes

CFLAGS = -Wall -Wextra -Werror -g

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "libft compiled !"

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "Objects deleted !"
	@/bin/rm -rf $(OBJ)

fclean: clean 
	@echo "libft.a deleted !"
	@/bin/rm -rf $(NAME) a.out

re: fclean all

.PHONY: all re fclean clean