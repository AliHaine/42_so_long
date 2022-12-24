#include "../so_long.h"

/*display_level(struct s_map *map)
{
	void;
}*/

static void setup_map_struct_img(struct s_map *map, struct s_core *core)
{
	mlx_image_t *g_img = mlx_new_image(core->mlx, 16, 16);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));

	while(map)
	{
		if (map->map_value.content == '0')
		{
			map->map_value.texture = mlx_load_xpm42("../assets/corner1.xpm");
			map->map_value.img = g_img;
			mlx_x
			//map->map_value.texture = mlx_xp(core->mlx, mlx_load_xpm42("../assets/corner1.xpm"));
			mlx_image_to_window(core->mlx, mlx_texture_to_image(core->mlx, map->map_value.texture), 0, 0);
		}
		map = map->next;
	}
}

void	game_loader(struct s_core *core)
{
	setup_map_struct_img(core->first, core);

	//display_level(core->first);
}