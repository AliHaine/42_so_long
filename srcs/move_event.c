#include "../so_long.h"

void	move_up(struct s_core *core)
{
	if (core->pos->map->top->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->top->map_value.content != '0')
	{
		if (core->pos->map->top->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->top->map_value.img);
		}
		core->pos->img->instances[0].y -= S;
		core->pos->map = core->pos->map->top;
		core->pos->map->map_value.content = '1';
		core->pos->map->map_value.content = 'P';
	}
}

void	move_down(struct s_core *core)
{
	if (core->pos->map->bot->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->bot->map_value.content != '0')
	{
		if (core->pos->map->bot->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->bot->map_value.img);
		}
		core->pos->img->instances[0].y += S;
		core->pos->map->map_value.content = '1';
		core->pos->map = core->pos->map->bot;
		core->pos->map->map_value.content = 'P';
	}
}

void	move_left(struct s_core *core)
{
	if (core->pos->map->prev->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->prev->map_value.content != '0')
	{
		if (core->pos->map->prev->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->prev->map_value.img);
		}
		core->pos->img->instances[0].x -= S;
		core->pos->map->map_value.content = '1';
		core->pos->map = core->pos->map->prev;
		core->pos->map->map_value.content = 'P';
	}
}

void	move_right(struct s_core *core)
{
	if (core->pos->map->next->map_value.content == 'M')
		exit(1);
	else if (core->pos->map->next->map_value.content != '0')
	{
		if (core->pos->map->next->map_value.content == 'C')
		{
			core->consumable--;
			mlx_delete_image(core->mlx, core->pos->map->next->map_value.img);
		}
		core->pos->img->instances[0].x += S;
		core->pos->map->map_value.content = '1';
		core->pos->map = core->pos->map->next;
		core->pos->map->map_value.content = 'P';
	}
}

void	move_event(struct s_core *core)
{
	if (mlx_is_key_down(core->mlx, MLX_KEY_UP))
		move_up(core);

	if (mlx_is_key_down(core->mlx, MLX_KEY_DOWN)) {
		move_down(core);
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_LEFT)) {
		move_left(core);
	}
	if (mlx_is_key_down(core->mlx, MLX_KEY_RIGHT)) {
		move_right(core);
	}
}