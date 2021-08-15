/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:35:07 by gshim             #+#    #+#             */
/*   Updated: 2021/07/26 19:06:27 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1size;
	int		s2size;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	i = -1;
	s1size = 0;
	while (s1[s1size] != '\0')
		s1size++;
	s2size = 0;
	while (s2[s2size] != '\0')
		s2size++;
	ret = (char *)malloc(sizeof(char) * (s1size + s2size + 1));
	if (!ret)
		return (0);
	ret[0] = '\0';
	ft_strcat(ret, (char *)s1);
	ft_strcat(ret, (char *)s2);
	return (ret);
}
