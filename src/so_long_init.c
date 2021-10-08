/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshim <gshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 09:31:27 by gshim             #+#    #+#             */
/*   Updated: 2021/10/08 00:51:34 by gshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *filename)
{
	int			fd;
	char		*line;
	t_vector	*vec;

	vec = vec_init();
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		closed(0, 2);
	get_next_line(fd, &line);
	append(vec, line);
	while (*line != '\0')
	{
		get_next_line(fd, &line);
		append(vec, line);
	}
	close(fd);
	if (validate_map(vec, game) < 0)
	{
		arr_free(vec);
		closed(game, 0);
	}
	game->map = vec->arr;
	free(vec);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->COL * TILE_SIZE,
			game->ROW * TILE_SIZE, "GSHIM");
	game->cnt = 0;
	game->point = 0;
	game->goal = 0;
}

void	img_init(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.img = mlx_png_file_to_image(game->mlx,
			"./textures/Cat_Sprite_Sheet.png", &img_width, &img_height);
	game->tile.img = mlx_png_file_to_image(game->mlx,
			"./textures/TX_Tileset_Grass.png", &img_width, &img_height);
	game->item.img = mlx_png_file_to_image(game->mlx,
			"./textures/rpg_icons_v1.png", &img_width, &img_height);
}

void	draw_easy(t_game *game, int i, int j, char item)
{
	if (item == '1')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->tile.img,
			1 * 32, 4 * 32, 32, 32, j * 64, i * 64, 64, 64, 0xFFFFFF);
	else if (item == '0')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->tile.img,
			0 * 32, 0 * 32, 32, 32, j * 64, i * 64, 64, 64, 0xFFFFFF);
	else if (item == 'C')
	{
		mlx_put_image_to_window_scale(game->mlx, game->win, game->item.img,
			5 + 0 * 20, 5 + 0 * 20, 18, 18, j * 64, i * 64, 64, 64, 0xFFFFFF);
		game->goal++;
	}
	else if (item == 'E')
		mlx_put_image_to_window_scale(game->mlx, game->win, game->item.img,
			5 + 5 * 20, 5 + 5 * 20, 18, 18, j * 64, i * 64, 64, 64, 0xFFFFFF);
	else if (game->map[i][j] == 'P')
	{
		game->pos_x = j;
		game->pos_y = i;
		game->map[i][j] = '0';
		printf("[DRAW_BG] spawn_x: %d, spawn_y: %d\n", game->pos_x, game->pos_y);
	}
}

void	draw_background(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->ROW)
	{
		j = -1;
		while (++j < game->COL)
		{
			draw_easy(game, i, j, game->map[i][j]);
		}
	}
}
