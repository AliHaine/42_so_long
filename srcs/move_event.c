/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:24:37 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/30 23:24:39 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(struct s_core *core)
{
	if (core->pos->map->top->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->top->map_value.content != '1')
	{
		if (core->pos->map->top->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->top->map_value.img);
			if (core->consumable == 0)
				core->exit->map_value.img->instances->enabled = 1;
		}
		core->pos->img->instances[0].y -= S;
		core->pos->map = core->pos->map->top;
		core->pos->map->map_value.content = '0';
		core->pos->map->map_value.content = 'P';
		core->pos->movenbr++;
		ft_putstr(ft_itoa(core->pos->movenbr));
		if (check_exit(core) == 1)
			exit(1);
	}
}

void	move_down(struct s_core *core)
{
	if (core->pos->map->bot->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->bot->map_value.content != '1')
	{
		if (core->pos->map->bot->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->bot->map_value.img);
			if (core->consumable == 0)
				core->exit->map_value.img->instances->enabled = 1;
		}
		core->pos->img->instances[0].y += S;
		core->pos->map->map_value.content = '0';
		core->pos->map = core->pos->map->bot;
		core->pos->map->map_value.content = 'P';
		core->pos->movenbr++;
		ft_putstr(ft_itoa(core->pos->movenbr));
		if (check_exit(core) == 1)
			exit(1);
	}
}

void	move_left(struct s_core *core)
{
	if (core->pos->map->prev->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->prev->map_value.content != '1')
	{
		if (core->pos->map->prev->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->prev->map_value.img);
			if (core->consumable == 0)
				core->exit->map_value.img->instances->enabled = 1;
		}
		core->pos->img->instances[0].x -= S;
		core->pos->map->map_value.content = '0';
		core->pos->map = core->pos->map->prev;
		core->pos->map->map_value.content = 'P';
		core->pos->dir = 0;
		mlx_delete_image(core->mlx, core->pos->img);
		core->pos->texture = mlx_load_png(P_G);
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		core->pos->movenbr++;
		ft_putstr(ft_itoa(core->pos->movenbr));
		mlx_image_to_window(core->mlx, core->pos->img,
			core->pos->map->map_value.x * S, core->pos->map->map_value.y * S);
		if (check_exit(core) == 1)
			exit(1);
	}
}

void	move_right(struct s_core *core)
{
	if (core->pos->map->next->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->next->map_value.content != '1')
	{
		if (core->pos->map->next->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->next->map_value.img);
			if (core->consumable == 0)
				core->exit->map_value.img->instances->enabled = 1;
		}
		core->pos->img->instances[0].x += S;
		core->pos->map->map_value.content = '0';
		core->pos->map = core->pos->map->next;
		core->pos->map->map_value.content = 'P';
		core->pos->dir = 1;
		mlx_delete_image(core->mlx, core->pos->img);
		core->pos->texture = mlx_load_png(P_D);
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		core->pos->movenbr++;
		ft_putstr(ft_itoa(core->pos->movenbr));
		mlx_image_to_window(core->mlx, core->pos->img,
			core->pos->map->map_value.x * S, core->pos->map->map_value.y * S);
		if (check_exit(core) == 1)
			exit(1);
	}
}

void	move_event(struct s_core *core)
{
	if (mlx_is_key_down(core->mlx, MLX_KEY_W)
		|| mlx_is_key_down(core->mlx, MLX_KEY_UP))
		move_up(core);
	if (mlx_is_key_down(core->mlx, MLX_KEY_S)
		|| mlx_is_key_down(core->mlx, MLX_KEY_DOWN))
		move_down(core);
	if (mlx_is_key_down(core->mlx, MLX_KEY_A)
		|| mlx_is_key_down(core->mlx, MLX_KEY_LEFT))
		move_left(core);
	if (mlx_is_key_down(core->mlx, MLX_KEY_D)
		|| mlx_is_key_down(core->mlx, MLX_KEY_RIGHT))
		move_right(core);
}
