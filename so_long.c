
#include "so_long.h"

mlx_image_t	*g_img;

void	hook(void *controler)
{
	mlx_t	*mlx;
	struct s_map *tile;
	mlx_image_t *img;

	mlx = ((t_dblist *)controler)->mlx;
	tile = ((t_dblist *)controler)->pos;
	img = tile->map_value.img;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 64;
}
/*
int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 128, 128);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/


int	main(int argc, char *argv[])
{
	t_dblist	map;

	map_loader(argv[1], &map);
	/*g_img = mlx_new_image(&map.mlx, 128, 128);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	mlx_image_to_window(&map.mlx, g_img, 0, 0);
	mlx_loop_hook(&map.mlx, &hook, &map.mlx);
	mlx_loop(&map.mlx);
	mlx_terminate(&map.mlx);*/
	if (argc != 2)
		return(print_enum_msg(ERROR_ARGS_NUMBER));

	return (0);
}
