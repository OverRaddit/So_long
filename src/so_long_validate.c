/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:20:01 by gshim             #+#    #+#             */
/*   Updated: 2021/12/30 13:03:12 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_vector *vec, t_game *game)
{
	int	row;
	int	col;
	int	i;

	col = ft_strlen(vec->arr[0]);
	row = vec->size - 1;
	i = -1;
	while (++i < row)
	{
		if (col != (int)ft_strlen(vec->arr[i]))
			return (-1);
		if (vec->arr[i][0] != '1' || vec->arr[i][col - 1] != '1')
			return (-2);
	}
	i = -1;
	while (++i < col)
	{
		if (vec->arr[0][i] != '1' || vec->arr[row - 1][i] != '1')
			return (-4);
	}
	game->ROW = row;
	game->COL = col;
	return (0);
}

static void	validate_init(int *player, int *exit, int *collect)
{
	*player = 0;
	*exit = 0;
	*collect = 0;
}

int	validate_map2(t_vector *vec, t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collect;

	validate_init(&player, &exit, &collect);
	i = -1;
	j = -1;
	while (++i < game->ROW)
	{
		j = 0;
		while (++j < game->COL)
		{
			if (vec->arr[i][j] == 'P')
				player++;
			else if (vec->arr[i][j] == 'E')
				exit++;
			else if (vec->arr[i][j] == 'C')
				collect++;
		}
	}
	if (!player || !exit || !collect || player > 1 || exit > 1)
		return (-1);
	return (0);
}
