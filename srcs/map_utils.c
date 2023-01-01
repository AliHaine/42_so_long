/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:26:16 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/30 23:26:18 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_and_disp_img(mlx_t *mlx, struct s_map_value *mv, char *path, int c)
{
	mv->texture = mlx_load_png(path);
	mv->img = mlx_texture_to_image(mlx, mv->texture);
	mlx_image_to_window(mlx, mv->img, mv->x * S, mv->y * S);
	mv->content = c;
}

void	i_or_c_action(struct s_core *core, struct s_map_value *mv)
{
	if (mv->content == 'C')
	{
		core->consumable--;
		mlx_delete_image(core->mlx, mv->img);
		if (core->consumable == 0)
			core->exit->mv.img->instances->enabled = 1;
	}
	else if (mv->content == 'I')
	{
		core->pos->item++;
		mlx_delete_image(core->mlx, mv->img);
		mv->texture = mlx_load_png(GROUND);
		mv->img = mlx_texture_to_image(core->mlx, mv->texture);
		mlx_image_to_window(core->mlx, mv->img,
			mv->x * S, mv->y * S);
	}
}

bool	check_exit(struct s_core *core)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = core->pos->map->mv.x;
	x2 = core->exit->mv.x;
	y1 = core->pos->map->mv.y;
	y2 = core->exit->mv.y;
	if (core->consumable == 0)
		if (x1 == x2 && y1 == y2)
			return (true);
	return (false);
}

bool	is_wall(struct s_map *map)
{
	if (map->bot == NULL)
		return (true);
	else if (map->top == NULL)
		return (true);
	else if (map->prev->mv.y != map->mv.y)
		return (true);
	else if (map->next->mv.y != map->mv.y)
		return (true);
	return (false);
}

bool	can_goto(int c)
{
	if (c == '1' || c == 'B')
		return (false);
	return (true);
}
