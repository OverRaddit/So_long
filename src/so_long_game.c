/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:32:49 by gshim             #+#    #+#             */
/*   Updated: 2021/10/08 00:51:39 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, int x2, int y2)
{
	if (game->map[y2][x2] == '1')
		return ;
	else if (game->map[y2][x2] == 'C')
	{
		game->map[y2][x2] = '0';
		game->point++;
	}
	else if (game->map[y2][x2] == 'E' && game->point == game->goal)
		closed(game, 1);
	if (game->map[game->pos_y][game->pos_x] == '0' ||
			game->map[game->pos_y][game->pos_x] == 'C')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->tile.img,
			0 * 32, 0 * 32, 32, 32,
			game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	else if (game->map[game->pos_y][game->pos_x] == 'E')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->item.img,
			5 + 5 * 20, 5 + 5 * 20, 18, 18,
			game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	game->pos_x = x2;
	game->pos_y = y2;
	game->cnt++;
}

static void	print_status(t_game *game)
{
	ft_putstr_fd("[", 0);
	ft_putnbr_fd(game->cnt, 0);
	ft_putstr_fd(" walk, (", 0);
	ft_putnbr_fd(game->point, 0);
	ft_putstr_fd(" / ", 0);
	ft_putnbr_fd(game->goal, 0);
	ft_putstr_fd(") point\n", 0);
}

int	deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		closed(game, 3);
	if (key_code == KEY_UP || key_code == KEY_W)
		move(game, game->pos_x, game->pos_y - 1);
	else if (key_code == KEY_DOWN || key_code == KEY_S)
		move(game, game->pos_x, game->pos_y + 1);
	else if (key_code == KEY_LEFT || key_code == KEY_A)
		move(game, game->pos_x - 1, game->pos_y);
	else if (key_code == KEY_RIGHT || key_code == KEY_S)
		move(game, game->pos_x + 1, game->pos_y);
	mlx_put_image_to_window_scale(game->mlx, game->win, game->img.img,
		1 * 32, 4 * 32, 32, 32,
		game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	print_status(game);
	return (0);
}

int	closed(t_game *game, int flag)
{
	if (flag == 0)
		ft_putstr_fd("MAP ERROR\n", 1);
	else if (flag == 1)
		ft_putstr_fd("GAME CLEAR\n", 1);
	else if (flag == 2)
		ft_putstr_fd("MAP FILE NOT FOUND\n", 1);
	else if (flag == 3)
		ft_putstr_fd("EXIT KEY PRESSED\n", 1);
	exit(0);
}

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
