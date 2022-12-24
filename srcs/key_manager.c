#include "../so_long.h"

static void	move_event(struct s_core *core)
{
	if (mlx_is_key_down(core->mlx, MLX_KEY_UP))
		core->pos->map_value.img->instances[0].y -= 64;
}

void	key_event(void *core)
{
	mlx_t	*mlx;
	struct s_map *tile;
	mlx_image_t *img;

	mlx = ((t_core *)core)->mlx;
	tile = ((t_core *)core)->pos;
	printf("tt%d", ((t_core *)core)->pos->map_value.img->instances[0].y);
	img = tile->map_value.img;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	move_event(core);
	/*if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 64;*/
}
