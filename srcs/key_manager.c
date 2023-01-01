/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:31 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/29 17:26:12 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	launch_animation(t_core *core, int *boul, int x, int y)
{
	*boul *= -1;
	if (*boul == 1)
	{
		mlx_delete_image(core->mlx, core->pos->img);
		if (core->pos->dir == 1)
			core->pos->texture = mlx_load_png(P_DA);
		else
			core->pos->texture = mlx_load_png(P_GA);
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		mlx_image_to_window(core->mlx, core->pos->img, x, y);
	}
	else
	{
		mlx_delete_image(core->mlx, core->pos->img);
		if (core->pos->dir == 1)
			core->pos->texture = mlx_load_png(P_D);
		else
			core->pos->texture = mlx_load_png(P_G);
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		mlx_image_to_window(core->mlx, core->pos->img, x, y);
		my_sleep(1.5);
	}
	hit_event(core);
	return (0);
}

void	loop_event(void *core)
{
	static int	boul = -1;

	if (mlx_is_key_down(((t_core *)core)->mlx, MLX_KEY_SPACE))
		launch_animation(core, &boul,
			((t_core *)core)->pos->map->map_value.x * S,
			((t_core *)core)->pos->map->map_value.y * S);
}

static int	build_event(struct s_core *core)
{
	 static int i = 0;

	 i++;
	 if (i == 2)
	 {
		 i = 0;
		 return (0);
	 }
	if (core->pos->item == 0)
		return (ft_putstr("Vous n'avez pas d'item\n"));
	if (core->pos->dir == 1)
	{
		if (core->pos->map->next->map_value.content != '0')
			return (printf("Vous ne pouvez pas build sur cette tile\n"));
		mlx_delete_image(core->mlx, core->pos->map->next->map_value.img);
		core->pos->map->next->map_value.texture = mlx_load_png(BLOC);
		core->pos->map->next->map_value.img = mlx_texture_to_image(core->mlx, core->pos->map->next->map_value.texture);
		mlx_image_to_window(core->mlx, core->pos->map->next->map_value.img,
							core->pos->map->next->map_value.x * S, core->pos->map->next->map_value.y * S);
		core->pos->map->next->map_value.content = 'B';
	}
	else
	{
		if (core->pos->map->prev->map_value.content != '0')
			return (printf("Vous ne pouvez pas build sur cette tile\n"));
		mlx_delete_image(core->mlx, core->pos->map->prev->map_value.img);
		core->pos->map->prev->map_value.texture = mlx_load_png(BLOC);
		core->pos->map->prev->map_value.img = mlx_texture_to_image(core->mlx, core->pos->map->prev->map_value.texture);
		mlx_image_to_window(core->mlx, core->pos->map->prev->map_value.img,
							core->pos->map->prev->map_value.x * S, core->pos->map->prev->map_value.y * S);
		core->pos->map->prev->map_value.content = 'B';
	}
	core->pos->item--;

	return (1);
}

void	key_event(mlx_key_data_t key_data, void *core)
{
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(((t_core *)core)->mlx);
	if (key_data.key == MLX_KEY_C)
		build_event(((t_core *)core));
	move_event(core);
}
