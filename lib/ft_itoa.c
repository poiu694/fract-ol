/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:01:05 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/21 16:19:46 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_get_size(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
		ret++;
	while (n != 0)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	sign = ft_get_sign(n);
	size = ft_get_size(n);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (--size >= 0)
	{
		ret[size] = ((n % 10) * sign) + '0';
		n = n / 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
