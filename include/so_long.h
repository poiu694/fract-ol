/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:57:00 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:13:42 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "../lib/libft.h"
# include "../mlx/mlx.h"

# define ERROR_EXIT 1
# define SUCCES_EXIT 0
# define EMPTY_MODE -1
# define EMPTY_FD 1

# define BLOCK_SIZE 64

# define MAP_EXTENSION ".ber"

# define COLLECTION 'C'
# define LADDER 'E'
# define EMPTY_BLOCK '0'
# define WALL_BLOCK '1'
# define PLAYER 'P'

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		row_len;
	int		col_len;
	int		is_valid_map;
	char	**map;
}	t_map;

typedef struct s_collection
{
	int		is_already_get;
	t_pos	pos;
}	t_collection;

typedef struct s_game_info
{
	int				count_of_move;
	int				count_of_collect;
	int				init_count_of_collect;
	t_pos			player_pos;
	t_pos			ladder_pos;
	t_collection	*collections;
}	t_game_info;

typedef struct s_node
{
	t_map		map_info;
	t_game_info	game_info;
	void		*mlx;
}	t_node;

void	guard_close(int fd);
int		guard_open(const char *path, int flag, int mode);
void	exit_error(const char *msg, int code);

void	free_node(t_node *node, int fd);

void	init_game_info(t_node *node);
void	init_node_map(t_node *node, const char *path);

#endif
