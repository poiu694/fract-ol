/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:40:17 by sangmlee          #+#    #+#             */
/*   Updated: 2022/07/02 19:19:04 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif
