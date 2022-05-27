# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:39:54 by sangmlee          #+#    #+#              #
#    Updated: 2022/05/27 16:51:50 by sangmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	fractol

MLX			=	libmlx.a
MLX_ROOT	=	mlx
SRCS		=	fract_ol.c \

OBJS		=	$(SRCS:.c=.o)

INCS		=	fract_ol.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -O3
CLIB		=	-L./$(MLX) -lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

AR          =   ar rc

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CLIB) -o $@ $^

$(MLX):
	$(MAKE) -C $(MLX_ROOT) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
