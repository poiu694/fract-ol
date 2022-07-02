/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@42student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:55:40 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:19:49 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
	if (array)
		free(array);
	array = NULL;
}

static void	free_game_info(t_node *node)
{
	if (node->game_info.collections)
		free(node->game_info.collections);
	node->game_info.collections = NULL;
}

static void	free_map_info(t_node *node)
{
	if (node->map_info.map)
		free_array(node->map_info.map);
	node->map_info.map = NULL;
}

void	free_node(t_node *node, int fd)
{
	free_game_info(node);
	free_map_info(node);
	node = NULL;
	if (fd != EMPTY_FD)
		guard_close(fd);
}
