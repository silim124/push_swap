# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 19:45:16 by silim             #+#    #+#              #
#    Updated: 2021/07/30 17:43:48 by silim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_strlen.c \
			ft_abs.c \
			ft_atoi.c \
			ft_isint.c \
			ft_isnum.c \
			ft_split.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strlcpy.c

OBJ		=	$(SRCS:.c=.o)
NAME	=	libft.a
CC		=	gcc -Wall -Werror -Wextra

all		:	$(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all
