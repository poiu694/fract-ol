# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:39:54 by sangmlee          #+#    #+#              #
#    Updated: 2022/07/02 19:25:40 by sangmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	so_long

LIB_DIR		=	./lib/
MLX_DIR		=	./mlx/
INC_DIR		=	./include/
SRC_DIR		=	./src/

SRCS_FILE	=	so_long.c \
				guard_utils.c \
				handle_error.c \
				handle_free.c \
				init_game_info.c \
				init_map_info.c \
				get_next_line.c \
				get_next_line_utils.c 	

SRCS		=	$(addprefix $(SRC_DIR), $(SRCS_FILE))

OBJS		=	$(SRCS:.c=.o)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3
CLIB		=	-L$(LIB_ROOT) -llibft.a -L$(MLX_ROOT) -llibmlx.a -framework OpenGL -framework AppKit

RM			=	rm -f

AR          =   ar rc

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAG) $(CLIB) -o $@ $^

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
