/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:31 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:03:33 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_event(struct s_core *core)
{
	/*double time;

	time = mlx_get_time() + 1;
	if (mlx_is_key_down(core->mlx, MLX_KEY_SPACE))
	{
		core->pos->texture = mlx_load_png("./assets/characters/p_a1.png");
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);
		//mlx_resize_image(mv->img, 64, 64);
		mlx_image_to_window(core->mlx, core->pos->img, core->pos->map->map_value.x * 64, core->pos->map->map_value.y * 64);
		time = mlx_get_time() + 1;

		while(mlx_get_time() < time)
			;
		printf("%f\n", mlx_get_time());
		mlx_delete_image(core->mlx, core->pos->img);
		core->pos->texture = mlx_load_png("./assets/characters/p_0.png");
		core->pos->img = mlx_texture_to_image(core->mlx, core->pos->texture);

	}
	//mlx_resize_image(mv->img, 64, 64);
	mlx_image_to_window(core->mlx, core->pos->img, core->pos->map->map_value.x * 64, core->pos->map->map_value.y * 64);*/

	if (mlx_is_key_down(core->mlx, MLX_KEY_UP))
	{
		//printf("b y of img %d // y of top %d\n", core->pos->img->instances[0].y - 64, core->pos->map->top->map_value.y * 64);
		if (((core->pos->img->instances[0].y - 5) - 60) <= ((core->pos->map->top->map_value.y * 64)))
		{
			if (core->pos->map->top->map_value.content == '0')
				return;
			printf("square change top, position : x:%d y:%d to x:%d y:%d\n", core->pos->map->map_value.x, core->pos->map->map_value.y, core->pos->map->top->map_value.x, core->pos->map->top->map_value.y);
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->top;
			core->pos->map->map_value.content = 'P';
			//load_img(&core->pos->map->map_value, core->mlx);
		}
		//printf("bef %d\n", core->pos->img->instances[0].y);
		core->pos->img->instances[0].y -= 5;
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_DOWN))
	{
		if (((core->pos->img->instances[0].y + 5) + 62) >= (((core->pos->map->bot->map_value.y * 64)) + 32))
		{
			if (core->pos->map->bot->map_value.content == '0')
				return;
			printf("square change bot, position : x:%d y:%d to x:%d y:%d\n", core->pos->map->map_value.x, core->pos->map->map_value.y, core->pos->map->bot->map_value.x, core->pos->map->bot->map_value.y);
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->bot;
			core->pos->map->map_value.content = 'P';
		}
		core->pos->img->instances[0].y += 5;
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_LEFT))
	{
		if (((core->pos->img->instances[0].x - 5)) <= ((core->pos->map->prev->map_value.x * 64) + 60))
		{
			if (core->pos->map->prev->map_value.content == '0')
				return;
			printf("square change gauche, position : x:%d y:%d to x:%d y:%d\n", core->pos->map->map_value.x, core->pos->map->map_value.y, core->pos->map->prev->map_value.x, core->pos->map->prev->map_value.y);
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->prev;
			core->pos->map->map_value.content = 'P';
		}
		core->pos->img->instances[0].x -= 5;
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_RIGHT))
	{
		if (((core->pos->img->instances[0].x + 5)) >= ((core->pos->map->next->map_value.x * 64) - 20))
		{if (core->pos->map->next->map_value.content == '0')
				return;
			printf("square change droite, position : x:%d y:%d to x:%d y:%d\n", core->pos->map->map_value.x, core->pos->map->map_value.y, core->pos->map->next->map_value.x, core->pos->map->next->map_value.y);
			core->pos->map->map_value.content = '1';
			core->pos->map = core->pos->map->next;
			core->pos->map->map_value.content = 'P';
		}
		core->pos->img->instances[0].x += 5;
	}
	/*if (mlx_is_key_down(core->mlx, MLX_KEY_UP))
	{
		if (core->pos->top->map_value.content != '0')
		{
			core->pos->map_value.img->instances[0].y -= 64;
			core->pos = core->pos->top;
			core->pos->map_value.content = 'P';
			load_img(&core->pos->map_value, core->mlx);
			core->pos->bot->map_value.content = '1';
			load_img(&core->pos->bot->map_value, core->mlx);
		}
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_DOWN))
	{
		if (core->pos->bot->map_value.content != '0')
		{
			core->pos->map_value.img->instances[0].y += 64;
			core->pos = core->pos->bot;
			core->pos->map_value.content = 'P';
			load_img(&core->pos->map_value, core->mlx);
			core->pos->top->map_value.content = '1';
			load_img(&core->pos->top->map_value, core->mlx);
		}
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_LEFT))
	{
		if (core->pos->prev->map_value.content != '0')
		{
			core->pos->map_value.img->instances[0].x -= 64;
			load_img(&core->pos->map_value, core->mlx);
			core->pos = core->pos->prev;
			load_img(&core->pos->map_value, core->mlx);
		}
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_RIGHT))
	{
		if (core->pos->next->map_value.content != '0')
		{
			core->pos->map_value.img->instances[0].x += 64;
			load_img(&core->pos->map_value, core->mlx);
			core->pos = core->pos->next;
			load_img(&core->pos->map_value, core->mlx);
		}
	}*/
}

void	key_event(void *core)
{
	if (mlx_is_key_down(((t_core *)core)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(((t_core *)core)->mlx);
	move_event(core);
	/*if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 64;*/
}
