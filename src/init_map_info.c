/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@42student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:55:40 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:18:02 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_map(t_node *node, int fd)
{
	char	*line;
	char	*temp_map;
	char	*tot_map_one_line;

	tot_map_one_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_map = ft_strjoin(tot_map_one_line, line);
		free(line);
		free(tot_map_one_line);
		tot_map_one_line = temp_map;
		free(temp_map);
	}
	node->map_info.map = ft_split(tot_map_one_line, '\n');
	free(tot_map_one_line);
	if (!node->map_info.map)
	{
		free_node(node, fd);
		exit_error("read map fail", ERROR_EXIT);
	}
}

static int	ft_arraylen(char **array)
{
	int	size;

	size = 0;
	while (array && array[size])
	{
		size++;
	}
	return (size);
}

static void	set_map_info(t_node *node, int fd)
{
	set_map(node, fd);
	node->map_info.row_len = ft_arraylen(node->map_info.map);
	node->map_info.col_len = ft_strlen(node->map_info.map[0]);
	//TODO: isValidMap Function
	node->map_info.is_valid_map = 1;
}

static void	initialize_to_null(t_node *node)
{
	node->game_info.collections = NULL;
	node->map_info.map = NULL;
}

void	init_node_map(t_node *node, const char *path)
{
	int	fd;

	initialize_to_null(node);
	fd = guard_open(path, O_RDONLY, EMPTY_MODE);
	set_map_info(node, fd);
	guard_close(fd);
}
