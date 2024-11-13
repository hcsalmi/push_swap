# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 16:01:02 by lsalmi            #+#    #+#              #
#    Updated: 2023/04/04 16:01:06 by lsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./srcs/
LIB_PATH = ./srcs/libft/

SRCS =	$(SRC_PATH)algo_lots.c $(SRC_PATH)algo_small.c \
		$(SRC_PATH)combinations_big.c $(SRC_PATH)combinations_small.c \
		$(SRC_PATH)compare.c $(SRC_PATH)execute_big.c \
		$(SRC_PATH)execute_small.c $(SRC_PATH)find_order.c $(SRC_PATH)lists.c \
		$(SRC_PATH)moves.c $(SRC_PATH)nodes.c \
		$(SRC_PATH)operations.c $(SRC_PATH)position_helpers.c \
		$(SRC_PATH)push_swap.c $(SRC_PATH)rotate.c $(SRC_PATH)sort_helpers.c \
		$(SRC_PATH)strategy.c $(SRC_PATH)utils.c $(SRC_PATH)validate.c \
		$(LIB_PATH)libft.a

INCLUDES = -I ./includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

# -C moves to the directory specified after it and performs the preceding command in that directory
$(NAME):
	make -s -C ./srcs/libft
	cc $(FLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

clean:
	make -s -C ./srcs/libft/ clean

fclean: clean
	make -s -C ./srcs/libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
