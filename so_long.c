/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:02:52 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/29 17:26:12 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	struct s_core	core;

	(void)argc;
	map_loader(argv[1], &core);
	game_loader(&core);
	mlx_key_hook(core.mlx, &key_event, &core.mlx);
	mlx_loop_hook(core.mlx, &loop_event, &core.mlx);
	mlx_loop(core.mlx);
	mlx_terminate(core.mlx);
	core.pos->img = mlx_put_string(core.mlx, "test", 64, 64);
	mlx_image_to_window(core.mlx, core.pos->img, 64, 64);
	return (0);
}
