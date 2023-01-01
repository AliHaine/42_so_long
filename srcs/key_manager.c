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
			((t_core *)core)->pos->map->mv.x * S,
			((t_core *)core)->pos->map->mv.y * S);
}

static int	build_event(struct s_core *core)
{
	static int	i = 0;

	if (i++ == 1)
	{
		i = 0;
		return (0);
	}
	if (core->pos->item == 0)
		return (ft_putstr("Vous n'avez pas d'item\n"));
	if (core->pos->dir == 1)
	{
		if (core->pos->map->next->mv.content != '0')
			return (ft_putstr("Vous ne pouvez pas build sur cette tile\n"));
		mlx_delete_image(core->mlx, core->pos->map->next->mv.img);
		load_and_disp_img(core->mlx, &core->pos->map->next->mv, BLOC, 'B');
	}
	else
	{
		if (core->pos->map->prev->mv.content != '0')
			return (ft_putstr("Vous ne pouvez pas build sur cette tile\n"));
		mlx_delete_image(core->mlx, core->pos->map->prev->mv.img);
		load_and_disp_img(core->mlx, &core->pos->map->prev->mv, BLOC, 'B');
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
