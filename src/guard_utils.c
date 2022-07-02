/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guard_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@42student.42seoul.kr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:55:40 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 18:52:31 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	guard_close(int fd)
{
	if (close(fd) == -1)
		exit_error("guard fail", ERROR_EXIT);
}

int	guard_open(const char *path, int flag, int mode)
{
	int	fd;

	if (mode == EMPTY_MODE)
		fd = open(path, flag);
	else
		fd = open(path, flag, mode);
	if (fd == -1)
		exit_error("open fail", ERROR_EXIT);
	return (fd);
}
