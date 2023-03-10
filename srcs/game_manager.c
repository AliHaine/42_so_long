/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:19 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/29 17:26:12 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_lvl(struct s_map_value *val, mlx_t *mlx)
{
	if (val->content == '1')
		val->texture = mlx_load_png(WALL);
	else if (val->content == '0')
		val->texture = mlx_load_png(GROUND);
	else if (val->content == 'C')
		val->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (val->content == 'E')
		val->texture = mlx_load_png("./assets/items/e.png");
	else if (val->content == 'M')
		val->texture = mlx_load_png("./assets/characters/e_0.png");
	else if (val->content == 'B')
		val->texture = mlx_load_png(BLOC);
	val->img = mlx_texture_to_image(mlx, val->texture);
	mlx_image_to_window(mlx, val->img, val->x * S, val->y * S);
}

static void	setup_map_struct_img(struct s_map *map, struct s_core *core)
{
	while (map)
	{
		if (map->mv.content != 'P')
		{
			if (map->mv.content == '1' && is_wall(map) == false)
				map->mv.content = 'B';
			display_lvl(&map->mv, core->mlx);
		}
		map = map->next;
	}
}

void	game_loader(struct s_core *core)
{
	setup_map_struct_img(core->first, core);
	core->pos->texture = mlx_load_png(P_D);
	core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
	mlx_image_to_window(core->mlx, core->pos->img,
		core->pos->map->mv.x * S, core->pos->map->mv.y * S);
	if (core->consumable == 0)
		core->exit->mv.img->instances->enabled = 1;
	else
		core->exit->mv.img->instances->enabled = 0;
	core->txt = mlx_put_string(core->mlx, "0", 0, 0);
}
