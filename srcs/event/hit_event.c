/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:08:19 by ayagmur           #+#    #+#             */
/*   Updated: 2023/01/01 19:08:21 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static bool	hit_bloc(t_map *map, mlx_t *mlx)
{
	if (map->map_value.acces <= 2)
	{
		map->map_value.texture = mlx_load_png(BLOC1);
	}
	else if (map->map_value.acces <= 4)
	{
		map->map_value.texture = mlx_load_png(BLOC2);
	}
	else
	{
		mlx_delete_image(mlx, map->map_value.img);
		map->map_value.texture = mlx_load_png(BITEM);
		map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
		mlx_image_to_window(mlx, map->map_value.img,
			map->map_value.x * S, map->map_value.y * S);
		map->map_value.content = 'I';
		return (true);
	}
	map->map_value.acces++;
	mlx_delete_image(mlx, map->map_value.img);
	map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
	mlx_image_to_window(mlx, map->map_value.img,
		map->map_value.x * S, map->map_value.y * S);
	return (true);
}

static bool	is_bloc(t_core *core)
{
	if (core->pos->map->next->map_value.content == 'B')
		return (hit_bloc(core->pos->map->next, core->mlx));
	else if (core->pos->map->prev->map_value.content == 'B')
		return (hit_bloc(core->pos->map->prev, core->mlx));
	else if (core->pos->map->bot->map_value.content == 'B')
		return (hit_bloc(core->pos->map->bot, core->mlx));
	else if (core->pos->map->top->map_value.content == 'B')
		return (hit_bloc(core->pos->map->top, core->mlx));
	return (false);
}

static bool	hit_emma(t_map *map, mlx_t *mlx)
{
	if (map->map_value.acces <= 2)
	{
		map->map_value.texture = mlx_load_png("./assets/characters/e_1.png");
	}
	else if (map->map_value.acces <= 4)
	{
		map->map_value.texture = mlx_load_png("./assets/characters/e_2.png");
	}
	else
	{
		mlx_delete_image(mlx, map->map_value.img);
		map->map_value.texture = mlx_load_png(GROUND);
		map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
		mlx_image_to_window(mlx, map->map_value.img,
			map->map_value.x * S, map->map_value.y * S);
		map->map_value.content = '0';
		return (true);
	}
	map->map_value.acces++;
	mlx_delete_image(mlx, map->map_value.img);
	map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
	mlx_image_to_window(mlx, map->map_value.img,
		map->map_value.x * S, map->map_value.y * S);
	return (true);
}

static bool	is_emma(t_core *core)
{
	if (core->pos->map->next->map_value.content == 'M')
		return (hit_emma(core->pos->map->next, core->mlx));
	else if (core->pos->map->prev->map_value.content == 'M')
		return (hit_emma(core->pos->map->prev, core->mlx));
	else if (core->pos->map->bot->map_value.content == 'M')
		return (hit_emma(core->pos->map->bot, core->mlx));
	else if (core->pos->map->top->map_value.content == 'M')
		return (hit_emma(core->pos->map->top, core->mlx));
	return (false);
}

void	hit_event(struct s_core *core)
{
	if (is_emma(core) == true)
		return ;
	else
		is_bloc(core);
}
