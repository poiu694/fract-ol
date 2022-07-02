/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:52:29 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/21 13:49:58 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_temp;

	if (n == 0 || dst == src)
		return (dst);
	dst_temp = dst;
	while (n)
	{
		*(unsigned char *)dst_temp = *(unsigned char *)src;
		dst_temp++;
		src++;
		n--;
	}
	return (dst);
}
