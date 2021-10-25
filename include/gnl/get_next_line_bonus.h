/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:59:49 by gshim             #+#    #+#             */
/*   Updated: 2021/08/22 21:55:05 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		my_strchr(const char *str);
char	*ft_strjoinfree(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
