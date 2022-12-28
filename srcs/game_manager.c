#include "../so_long.h"

/*display_level(struct s_map *map)
{
	void;
}*/

static void	load_img(struct s_map_value *mv, mlx_t *mlx, int content)
{
	if (content == '0')
		mv->texture = mlx_load_png("./assets/deco/w_0.png");
	else if (content == '1')
		mv->texture = mlx_load_png("./assets/deco/g_0.png");
	else if (content == 'C')
		mv->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (content == 'E')
		mv->texture = mlx_load_png("./assets/items/g_gem.png");
	else if (content == 'P')
		mv->texture = mlx_load_png("./assets/characters/p_0.png");
	mv->img = mlx_texture_to_image(mlx, mv->texture);
	mlx_resize_image(mv->img, 64, 64);
	mlx_image_to_window(mlx, mv->img, mv->x * 64, mv->y * 64);
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
			else if (map->map_value.content == 'E')
				e++;
			else if (map->map_value.content == 'C')
				c++;
			load_img(&map->map_value, core->mlx, map->map_value.content);
		}
		else
			load_img(&map->map_value, core->mlx, map->map_value.content);
		map = map->next;
	}
	/*
	if (p != 1 || e != 1 || c != map->consumable)
	{
		//ERROR
	}

	if (content == '0')
	{
		map->map_value.content = '0';
		map->map_value.acces = 0;
	}
	else if (content == '1')
		map->map_value.content = '1';
	else if (content == 'C')
		map->map_value.content = 'C';
	else if (content == 'E')
	{
		map->map_value.content = 'E';
		if (exit == 0)
			exit++;
		else
		{
			print_enum_msg(ERROR_EXIT_TOHIGH);
			return (0);
		}
	}
	else if (content == 'P')
	{
		core->pos = map;
		map->map_value.content = 'P';
		if (player == 0)
			player++;
		else
		{
			print_enum_msg(ERROR_MAP);
			return (0);
		}
	}
	else if (content == 'Z')
	{
		if (player == 0)
		{
			print_enum_msg(ERROR_NO_PLAYER);
			return (0);
		}
		else if (exit == 0)
		{
			print_enum_msg(ERROR_NO_EXIT);
			return (0);
		}
	}
	else
	{
		print_enum_msg(ERROR_MAP);
		return (0);
	}
	return (1);

	(void)map;
	t_map_value mv;

	core->pos->map_value.texture = mlx_load_png("./assets/characters/p_0.png");
	core->pos->map_value.img = mlx_texture_to_image(core->mlx, core->pos->map_value.texture);
	//mlx_resize_image(core->pos->map_value.img, 64, 64);
	mv = core->pos->map_value;
	mlx_image_to_window(core->mlx, mv.img, mv.x * 64, mv.y * 64);*/
}

void	game_loader(struct s_core *core)
{
	setup_map_struct_img(core->first, core);

	//display_level(core->first);
}
