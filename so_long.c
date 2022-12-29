/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:02:52 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:03:01 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	struct s_core	core;

	(void)argc;

	map_loader(argv[1], &core);
	game_loader(&core);
	//g_img = mlx_new_image(core.mlx, 64, 64);
	//memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	//mlx_image_to_window(core.mlx, g_img, core.pos->map_value.x * 64, core.pos->map_value.y * 64);
	//core.pos->map_value.img = g_img;
	mlx_loop_hook(core.mlx, &key_event, &core.mlx);
	mlx_loop(core.mlx);
	mlx_terminate(core.mlx);
	//if (argc != 2)
	//	return(print_enum_msg(ERROR_ARGS_NUMBER));

	return (0);
}
