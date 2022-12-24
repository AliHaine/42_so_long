#include "../so_long.h"

void set_tb_struct(struct s_map *map, int size)
{
	t_map *iterator;

	iterator = map;
	while(size--)
		iterator = iterator->prev;
	map->top = iterator;
	iterator->bot = map;
}

void	setup_struct_value(struct s_core *core, t_three_int *three_int)
{
	core->first = NULL;
	core->last = NULL;
	three_int->x = 0;
	three_int->y = 0;
	three_int->size = 0;
}
