
#include "so_long.h"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);

	return (0);
}