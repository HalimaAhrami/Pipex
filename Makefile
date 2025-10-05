# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 15:36:07 by h-el-ahr          #+#    #+#              #
#    Updated: 2025/04/04 19:19:19 by h-el-ahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Werror -Wall -Wextra


SRCS = 	pipex.c util.c


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -L./libft -lft


fclean : clean
	rm -rf $(NAME) $(OBJS)
	make fclean -C libft

clean :
	rm -rf $(NAME) $(OBJS)
	make clean -C libft

re : fclean all

.PHONY: clean fclean re
