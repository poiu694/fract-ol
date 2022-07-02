/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@42student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:55:40 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:04:17 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_node(t_node *node, const char *path)
{
	node->mlx = mlx_init();
	if (!node->mlx)
		exit_error("mlx init error", ERROR_EXIT);
	init_node_map(node, path);
	init_game_info(node);
}

int	main(int argc, char **argv)
{
	t_node	node;

	if (argc != 2)
		exit_error("PUT THE MAP('*.ber", ERROR_EXIT);
	init_node(&node, argv[1]);
	free_node(&node, EMPTY_FD);
}
