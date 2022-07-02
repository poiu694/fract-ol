/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:26:05 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/21 14:23:38 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char)c;
	if (target == 0)
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == target)
			return ((char *)s);
		s++;
	}
	return (0);
}
