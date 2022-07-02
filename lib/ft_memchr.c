/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:11:10 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/21 13:47:55 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	target;
	unsigned char	*s_temp;

	target = (unsigned char)c;
	s_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*s_temp == target)
			return ((void *)s_temp);
		i++;
		s_temp++;
	}
	return (0);
}
