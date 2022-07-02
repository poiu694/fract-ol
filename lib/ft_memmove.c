/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:52:29 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/21 15:07:09 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	if (dst == src)
		return (dst);
	src_temp = (unsigned char *)src;
	dst_temp = (unsigned char *)dst;
	if (src_temp < dst_temp)
		while (n--)
			dst_temp[n] = src_temp[n];
	else
		ft_memcpy(dst_temp, src_temp, n);
	return (dst);
}
