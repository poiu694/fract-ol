/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@42student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:55:40 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:15:23 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_collection_cnt(t_node *node)
{
	int	row;
	int	col;
	int	cnt;

	if (!node || !node->map_info.map)
	{
		free_node(node, EMPTY_FD);
		exit_error("init node fail", ERROR_EXIT);
	}
	cnt = 0;
	row = 0;
	while (row < node->map_info.row_len)
	{
		col = 0;
		while (col < node->map_info.col_len)
		{
			if (node->map_info.map[row][col] == COLLECTION)
				cnt++;
			col++;
		}
		row++;
	}
	return (cnt);
}

static t_collection	create_collection(int x, int y)
{
	t_collection	collection;

	collection.pos.x = x;
	collection.pos.y = y;
	collection.is_already_get = 0;
	return (collection);
}

static void	set_collection_info(t_node *node, int cnt)
{
	int	row;
	int	col;
	int	idx;

	if (!node || !node->map_info.map)
	{
		free_node(node, EMPTY_FD);
		exit_error("init node fail", ERROR_EXIT);
	}
	row = 0;
	idx = 0;
	while (row < node->map_info.row_len && idx < cnt)
	{
		col = 0;
		while (col < node->map_info.col_len && idx < cnt)
		{
			if (node->map_info.map[row][col] == COLLECTION)
			{
				node->game_info.collections[idx] = create_collection(row, col);
			}
		}
		row++;
	}
}

static void	set_collections_info(t_node *node)
{
	int	collection_cnt;

	collection_cnt = get_collection_cnt(node);
	node->game_info.collections = (t_collection *)malloc(sizeof(t_collection)
			* collection_cnt + 1);
	if (!node->game_info.collections)
	{
		free_node(node, EMPTY_FD);
		exit_error("init collection fail", ERROR_EXIT);
	}
	set_collection_info(node, collection_cnt);
	node->game_info.init_count_of_collect = collection_cnt;
}	

void	init_game_info(t_node *node)
{
	set_collections_info(node);
	node->game_info.count_of_move = 0;
	node->game_info.count_of_collect = 0;
	node->game_info.player_pos.x = 0;
	node->game_info.player_pos.y = 0;
	node->game_info.ladder_pos.x = 0;
	node->game_info.ladder_pos.y = 0;
}
