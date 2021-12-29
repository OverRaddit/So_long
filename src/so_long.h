#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../include/libft/libft.h"
# include "../include/minilibx_mms_20210621/mlx.h"
# include "../include/gnl/get_next_line.h"
# include "../include/dynamic_array/dynamic_array.h"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	tile;
	t_img	item;
	int		cnt;
	int		point;
	int		goal;
	int		pos_x;
	int		pos_y;

	char	**map;
	int		ROW;
	int		COL;
}				t_game;

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 //Exit program key code

# define KEY_ESC			53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13

# define TILE_SIZE 64

int		closed(int flag);
void	draw_background(t_game *game);
void	move(t_game *game, int x2, int y2);
int		deal_key(int key_code, t_game *game);
int		validate_map(t_vector *vec, t_game *game);
void	game_init(t_game *game, char *filename);
void	window_init(t_game *game);
void	img_init(t_game *game);

#endif
