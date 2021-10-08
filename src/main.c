#include "so_long.h"

// 현재 함수는 6개
int	main_loop(t_game *game)
{
	mlx_put_image_to_window_scale(game->mlx, game->win, game->img.img,
		1 * 32, 4 * 32, 32, 32,
		game->pos_x * 64, game->pos_y * 64, 64, 64, 0xFFFFFF);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("please execute like ./server [mapname]", 0);
		return (-1);
	}
	game_init(&game, argv[1]);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &closed, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	draw_background(&game);
	mlx_put_image_to_window_scale(game.mlx, game.win, game.img.img,
		1 * 32, 4 * 32, 32, 32,
		game.pos_x * 64, game.pos_y * 64, 64, 64, 0xFFFFFF);
	mlx_loop(game.mlx);
}
