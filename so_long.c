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

	if (argc != 2)
	{
		print_enum_msg(ERROR);
		return (0);
	}
	map_loader(argv[1], &core);
	game_loader(&core);
	mlx_key_hook(core.mlx, &key_event, &core.mlx);
	mlx_loop_hook(core.mlx, &loop_event, &core.mlx);
	mlx_loop(core.mlx);
	mlx_terminate(core.mlx);
	return (0);
}
