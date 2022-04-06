# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 18:42:33 by tmerida-          #+#    #+#              #
#    Updated: 2022/03/28 18:42:34 by tmerida-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	= 	fdf

SRC 	=	srcs/fdf.c \
			srcs/leer_fichero.c \
			srcs/contador_words.c \
			srcs/dibujamos.c \
			srcs/info_iso.c

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

LIBFT 	= libft/libft.a

MLXLINK = -L minilibx
MINILIBX = -I minilibx
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
		make -C minilibx
		make -C libft
		$(CC) $(CFLAG) $(MLXLINK) $(MINILIBX) $(LIBFT) $(OPENGL) $^ -o $(NAME)

clean:
		make clean -C minilibx
		make clean -C libft
		/bin/rm -rf srcs/*.o

fclean: clean 
		make fclean -C libft
		/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re