/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:41:30 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/23 13:24:52 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*ret;
	unsigned char	*s_temp;
	unsigned char	target;

	i = 0;
	ret = 0;
	target = (unsigned char)c;
	s_temp = (unsigned char *)s;
	while (s_temp[i])
	{
		if (s_temp[i] == target)
			ret = ((char *)s + i);
		i++;
	}
	if (s[i] == target)
		return ((char *)s + i);
	return (ret);
}
