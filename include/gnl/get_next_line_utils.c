/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:00:43 by gshim             #+#    #+#             */
/*   Updated: 2021/08/22 23:11:59 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_strchr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	destlen;
	int	i;

	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	int		s1size;
	int		s2size;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1size + s2size + 1));
	if (!ret)
		return (0);
	ret[0] = '\0';
	ft_strcat(ret, (char *)s1);
	ft_strcat(ret, (char *)s2);
	free((void *)s1);
	return (ret);
}
