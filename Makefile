# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 19:44:05 by silim             #+#    #+#              #
#    Updated: 2021/07/29 18:58:35 by silim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c \
			srcs/add_pop.c \
			srcs/clear.c \
			srcs/init_stack.c \
			srcs/order_stack.c \
			srcs/push_swap.c \
			srcs/reverse_rotate.c \
			srcs/rotate.c \
			srcs/sort_stack.c

OBJ		=	$(SRCS:.c=.o)
NAME	=	push_swap
CC		=	gcc -Wall -Werror -Wextra
LIBFT	=	./libft/libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		make all -C libft/
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean	:
			rm -f $(OBJ)
			make clean -C libft/

fclean	:
			rm -f $(OBJ)
			rm -f $(NAME)
			make fclean -C libft/

re		:	fclean all

.PHONY: all clean fclean re
