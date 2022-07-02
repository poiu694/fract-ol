/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:22:54 by sangmlee          #+#    #+#             */
/*   Updated: 2021/12/01 14:04:56 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\r' || c == '\n'
		|| c == '\t' || c == '\v' || c == ' ');
}

static int	get_ans_with_range_check(long long nbr, int sign)
{
	if (nbr < 0)
		return ((sign + 1) / -2);
	return ((int)(nbr * sign));
}

int	ft_atoi(const char *str)
{
	long long	sum;
	int			sign;
	int			ans;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	sum = 0;
	while (ft_isdigit(*str))
	{
		sum = sum * 10;
		sum = sum + (long long)(*str - '0');
		str++;
	}
	ans = get_ans_with_range_check(sum, sign);
	return (ans);
}
