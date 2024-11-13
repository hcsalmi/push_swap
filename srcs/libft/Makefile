# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:11:19 by lsalmi            #+#    #+#              #
#    Updated: 2021/11/23 18:22:55 by lsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I$(HDR_PATH)

HDR_PATH = ./includes/
OBJ_PATH = ./objects/

SRC = ./srcs/*.c ./srcs/ft_printf/*.c

OBJ = $(OBJ_PATH)*.o

$(NAME):
	mkdir -p $(OBJ_PATH)
	cc -c $(FLAGS) $(SRC)
	mv *.o $(OBJ_PATH)
	ar rc $(NAME) $(OBJ)
	@echo "Executable $(NAME) created"

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_PATH)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Executable $(NAME) deleted"

re: fclean all
