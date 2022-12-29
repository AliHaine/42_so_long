/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:19 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:03:22 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*display_level(struct s_map *map)
{
	void;
}*/

void	load_img(void *mv, mlx_t *mlx)
{
	if (((t_map_value *)mv)->content == '0')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/w_0.png");
	else if (((t_map_value *)mv)->content == '1')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/deco/g_0.png");
	else if (((t_map_value *)mv)->content == 'C')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (((t_map_value *)mv)->content == 'E')
		((t_map_value *)mv)->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (((t_player *)mv)->map->map_value.content == 'P')
	{
		((t_player *) mv)->texture = mlx_load_png("./assets/characters/p_0.png");
		((t_player *)mv)->img = mlx_texture_to_image(mlx, ((t_player *)mv)->texture);
		//mlx_resize_image(mv->img, 64, 64);
		mlx_image_to_window(mlx, ((t_player *)mv)->img, ((t_player *)mv)->map->map_value.x * 64, ((t_player *)mv)->map->map_value.y * 64);
		return ;
	}
	((t_map_value *)mv)->img = mlx_texture_to_image(mlx, ((t_map_value *)mv)->texture);
	//mlx_resize_image(mv->img, 64, 64);
	mlx_image_to_window(mlx, ((t_map_value *)mv)->img, ((t_map_value *)mv)->x * 64, ((t_map_value *)mv)->y * 64);
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
				load_img(&map->map_value, core->mlx);
			}
		}
		else
			load_img(&map->map_value, core->mlx);
		map = map->next;
	}
}

void test_parcour(struct s_core *s)
{
	t_map *pelem = s->last;
	while(pelem)
	{
		printf("content %c ", pelem->map_value.content);
		printf("x %d ", pelem->map_value.x);
		printf("y %d\n", pelem->map_value.y);
		printf("prev content %c ", pelem->prev->map_value.content);
		printf("x %d ", pelem->prev->map_value.x);
		printf("y %d\n", pelem->prev->map_value.y);
		pelem = pelem->prev;
	}
}

void	game_loader(struct s_core *core)
{
	//test_parcour(core);
	setup_map_struct_img(core->first, core);
	load_img(core->pos, core->mlx);
	key_event(core);

	//display_level(core->first);
}
