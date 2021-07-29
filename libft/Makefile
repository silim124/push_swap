# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sochoi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 14:27:33 by sochoi            #+#    #+#              #
#    Updated: 2020/10/10 02:16:29 by sochoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_isblank.c ft_iscomma.c ft_strlen.c ft_strchr.c ft_isdigit.c ft_strdup.c ft_bzero.c ft_strncmp.c

OBJ			=	$(SRCS:.c=.o)

NAME		=	libft.a

all			:	$(NAME)

.c.o		:
				gcc -Wall -Werror -Wextra -c $< -o $@ -I ./

$(NAME)		:	$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
