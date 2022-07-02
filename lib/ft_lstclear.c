/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:04:49 by sangmlee          #+#    #+#             */
/*   Updated: 2021/11/23 17:34:12 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	size_t	i;
	size_t	len;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	i = 0;
	len = ft_lstsize(*lst);
	while (i < len)
	{
		if (*lst == NULL)
			break ;
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
