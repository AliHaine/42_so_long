#include "../so_long.h"

static int	check_content_pe(int content)
{
	static int exit = 0;
	static int player = 0;

	if (content == 'E')
	{
		if (exit == 0)
			exit++;
		else
			return (print_enum_msg(ERROR_EXIT_TOHIGH));
	}
	else if (content == 'P')
	{
		if (player == 0)
			player++;
		else
			return (print_enum_msg(ERROR_MAP));
	}
	else
	{
		if (player == 0)
			return (print_enum_msg(ERROR_NO_PLAYER));
		else if (exit == 0)
			return (print_enum_msg(ERROR_NO_EXIT));
	}
	return (1);
}

int	check_content(int content, struct s_core *core)
{
	if (content == '0' || content == '1' || content == 'X')
		return (1);
	else if (content == 'C')
		core->consumable++;
	else if (content == 'E' || content == 'P' || content == 'Z')
		return (check_content_pe(content));
	else
		return (print_enum_msg(ERROR_MAP));
	return (1);
}

int	check_wall(struct s_map *map, struct s_three_int *three_int, int x) {
	if (three_int->y == 0) {
		if (map->map_value.content != '0')
			return print_enum_msg(ERROR_NO_WALL);
	} else if (three_int->x == 0 && map->prev->map_value.y != map->map_value.y) {
		if (map->map_value.content != '0')
			return print_enum_msg(ERROR_NO_WALL);
	} else if (x == three_int->size) {
		if (map->map_value.content != '0')
			return print_enum_msg(ERROR_NO_WALL);
	}
	return (1);
}

void	check_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b' && file[i - 4] == '.')
		return ;
	print_enum_msg(ERROR_MAP);
	exit(0);
}