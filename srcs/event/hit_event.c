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
	if (map->mv.acces <= 2)
	{
		map->mv.texture = mlx_load_png(BLOC1);
	}
	else if (map->mv.acces <= 4)
	{
		map->mv.texture = mlx_load_png(BLOC2);
	}
	else
	{
		mlx_delete_image(mlx, map->mv.img);
		map->mv.texture = mlx_load_png(BITEM);
		map->mv.img = mlx_texture_to_image(mlx, map->mv.texture);
		mlx_image_to_window(mlx, map->mv.img,
			map->mv.x * S, map->mv.y * S);
		map->mv.content = 'I';
		return (true);
	}
	map->mv.acces++;
	mlx_delete_image(mlx, map->mv.img);
	map->mv.img = mlx_texture_to_image(mlx, map->mv.texture);
	mlx_image_to_window(mlx, map->mv.img,
		map->mv.x * S, map->mv.y * S);
	return (true);
}

static bool	is_bloc(t_core *core)
{
	if (core->pos->map->next->mv.content == 'B')
		return (hit_bloc(core->pos->map->next, core->mlx));
	else if (core->pos->map->prev->mv.content == 'B')
		return (hit_bloc(core->pos->map->prev, core->mlx));
	else if (core->pos->map->bot->mv.content == 'B')
		return (hit_bloc(core->pos->map->bot, core->mlx));
	else if (core->pos->map->top->mv.content == 'B')
		return (hit_bloc(core->pos->map->top, core->mlx));
	return (false);
}

static bool	hit_emma(t_map *map, mlx_t *mlx)
{
	if (map->mv.acces <= 2)
	{
		map->mv.texture = mlx_load_png("./assets/characters/e_1.png");
	}
	else if (map->mv.acces <= 4)
	{
		map->mv.texture = mlx_load_png("./assets/characters/e_2.png");
	}
	else
	{
		mlx_delete_image(mlx, map->mv.img);
		map->mv.texture = mlx_load_png(GROUND);
		map->mv.img = mlx_texture_to_image(mlx, map->mv.texture);
		mlx_image_to_window(mlx, map->mv.img,
			map->mv.x * S, map->mv.y * S);
		map->mv.content = '0';
		return (true);
	}
	map->mv.acces++;
	mlx_delete_image(mlx, map->mv.img);
	map->mv.img = mlx_texture_to_image(mlx, map->mv.texture);
	mlx_image_to_window(mlx, map->mv.img,
		map->mv.x * S, map->mv.y * S);
	return (true);
}

static bool	is_emma(t_core *core)
{
	if (core->pos->map->next->mv.content == 'M')
		return (hit_emma(core->pos->map->next, core->mlx));
	else if (core->pos->map->prev->mv.content == 'M')
		return (hit_emma(core->pos->map->prev, core->mlx));
	else if (core->pos->map->bot->mv.content == 'M')
		return (hit_emma(core->pos->map->bot, core->mlx));
	else if (core->pos->map->top->mv.content == 'M')
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
