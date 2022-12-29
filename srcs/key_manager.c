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

void	hit_emma(t_map *map, mlx_t *mlx)
{
	printf("%d\n", map->map_value.acces);
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
		map->map_value.texture = mlx_load_png("./assets/deco/w.png");
		map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
		mlx_image_to_window(mlx, map->map_value.img, map->map_value.x * S, map->map_value.y * S);
		return ;
	}
	map->map_value.acces++;
	mlx_delete_image(mlx, map->map_value.img);
	map->map_value.img = mlx_texture_to_image(mlx, map->map_value.texture);
	mlx_image_to_window(mlx, map->map_value.img, map->map_value.x * S, map->map_value.y * S);
}

void	is_emma(t_core *core)
{
	if (core->pos->map->next->map_value.content == 'M')
	{
		hit_emma(core->pos->map->next, core->mlx);
	}
	else if (core->pos->map->prev->map_value.content == 'M')
	{
		hit_emma(core->pos->map->prev, core->mlx);
	}
	else if (core->pos->map->bot->map_value.content == 'M')
	{
		hit_emma(core->pos->map->bot, core->mlx);
	}
	else if (core->pos->map->top->map_value.content == 'M')
	{
		hit_emma(core->pos->map->top, core->mlx);
	}
}

int	launch_animation(t_core *core, int *boul)
{
	*boul *= -1;
	if (*boul == 1) {
		mlx_delete_image(core->mlx, core->pos->img);
		core->pos->texture = mlx_load_png("./assets/characters/p_a2.png");
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		mlx_image_to_window(core->mlx, core->pos->img, core->pos->map->map_value.x * S,
							core->pos->map->map_value.y * S);
	}
	else
	{
		mlx_delete_image(core->mlx, core->pos->img);
		core->pos->texture = mlx_load_png("./assets/characters/p_0.png");
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		mlx_image_to_window(core->mlx, core->pos->img, core->pos->map->map_value.x * S,
							core->pos->map->map_value.y * S);
		my_sleep(1.5);
	}
	is_emma(core);
	return (0);
}

static void	move_event(struct s_core *core)
{
	if (mlx_is_key_down(core->mlx, MLX_KEY_UP))
	{
		if (core->pos->map->top->map_value.content == 'M')
			exit(1);
		else if (core->pos->map->top->map_value.content != '0')
		{
			core->pos->img->instances[0].y -= S;
			core->pos->map = core->pos->map->top;
			core->pos->map->map_value.content = '1';
			core->pos->map->map_value.content = 'P';
		}
	}

	if (mlx_is_key_down(core->mlx, MLX_KEY_DOWN))
	{
		if (core->pos->map->bot->map_value.content == 'M')
			exit(1);
		else if (core->pos->map->bot->map_value.content != '0')
		{
			core->pos->img->instances[0].y += S;
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->bot;
			core->pos->map->map_value.content = 'P';
		}
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_LEFT))
	{
		if (core->pos->map->prev->map_value.content == 'M')
			exit(1);
		else if (core->pos->map->prev->map_value.content != '0')
		{
			core->pos->img->instances[0].x -= S;
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->prev;
			core->pos->map->map_value.content = 'P';
		}
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_RIGHT))
	{
		if (core->pos->map->next->map_value.content == 'M')
			exit(1);
		else if (core->pos->map->next->map_value.content != '0')
		{
			core->pos->img->instances[0].x += S;
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->next;
			core->pos->map->map_value.content = 'P';
		}
	}
}

void	loop_event(void *core)
{
	static int	boul = -1;

	if (mlx_is_key_down(((t_core *)core)->mlx, MLX_KEY_SPACE))
		launch_animation(core, &boul);
}

void	key_event(mlx_key_data_t key_data, void *core)
{
	(void)key_data;
	if (mlx_is_key_down(((t_core *)core)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(((t_core *)core)->mlx);
	move_event(core);
}
