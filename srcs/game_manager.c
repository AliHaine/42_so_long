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

void	display_level(void *mv, mlx_t *mlx)
{
	if (((t_map_value *)mv)->content == '0')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/g.png");
	else if (((t_map_value *)mv)->content == '1')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/w.png");
	else if (((t_map_value *)mv)->content == 'C')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (((t_map_value *)mv)->content == 'E')
	{
		((t_map_value *) mv)->texture = mlx_load_png("./assets/items/e.png");
		((t_map_value *)mv)->img = mlx_texture_to_image(mlx, ((t_map_value *)mv)->texture);
		mlx_image_to_window(mlx, ((t_map_value *)mv)->img, ((t_map_value *)mv)->x * S, ((t_map_value *)mv)->y * S);
		((t_map_value *)mv)->img->enabled = 0;
		return ;
	}
	else if (((t_map_value *)mv)->content == 'M')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/characters/e_0.png");
	else if (((t_player *)mv)->map->map_value.content == 'P')
	{
		((t_player *) mv)->texture = mlx_load_png("./assets/characters/p_0.png");
		((t_player *)mv)->img = mlx_texture_to_image(mlx, ((t_player *)mv)->texture);
		mlx_image_to_window(mlx, ((t_player *)mv)->img, ((t_player *)mv)->map->map_value.x * S, ((t_player *)mv)->map->map_value.y * S);
		return ;
	}
	((t_map_value *)mv)->img = mlx_texture_to_image(mlx, ((t_map_value *)mv)->texture);
	mlx_image_to_window(mlx, ((t_map_value *)mv)->img, ((t_map_value *)mv)->x * S, ((t_map_value *)mv)->y * S);
}

void	load_img(void *mv, mlx_t *mlx)
{
	if (((t_map_value *)mv)->content == '0')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/g.png");
	else if (((t_map_value *)mv)->content == '1')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/w.png");
	else if (((t_map_value *)mv)->content == 'C')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (((t_map_value *)mv)->content == 'E')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/items/e.png");
	else if (((t_map_value *)mv)->content == 'M')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/characters/e_0.png");
	else if (((t_player *)mv)->map->map_value.content == 'P')
	{
		((t_player *) mv)->texture = mlx_load_png("./assets/characters/p_0.png");
		((t_player *)mv)->img = mlx_texture_to_image(mlx, ((t_player *)mv)->texture);
		mlx_image_to_window(mlx, ((t_player *)mv)->img, ((t_player *)mv)->map->map_value.x * S, ((t_player *)mv)->map->map_value.y * S);
		return ;
	}
	((t_map_value *)mv)->img = mlx_texture_to_image(mlx, ((t_map_value *)mv)->texture);
	mlx_image_to_window(mlx, ((t_map_value *)mv)->img, ((t_map_value *)mv)->x * S, ((t_map_value *)mv)->y * S);
}

static void setup_map_struct_img(struct s_map *map, struct s_core *core)
{
	short	p;
	short	e;
	short	c;

	p = 0;
	e = 0;
	c = 0;
	while(map)
	{
		if (map->map_value.acces)
		{
			if (map->map_value.content == 'P')
				p++;
			else
			{
				if (map->map_value.content == 'E')
					e++;
				else if (map->map_value.content == 'C')
					c++;
				display_level(&map->map_value, core->mlx);
			}
		}
		else
			display_level(&map->map_value, core->mlx);
		map = map->next;
	}
}

void	game_loader(struct s_core *core)
{
	//test_parcour(core);
	setup_map_struct_img(core->first, core);
	if (core->consumable == 0) {
		core->exit->map_value.img->enabled = 1;
	}
	printf("exx%p\n", core->exit);
	printf("poi%p\n", core->pos);
	load_img(core->pos, core->mlx);
	//key_event(NULL, core);

	//display_level(core->first);
}
