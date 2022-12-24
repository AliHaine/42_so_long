#include "../so_long.h"

void test_parcour(struct s_core *s)
{
	t_map *pelem = s->last;
	while(pelem)
	{
		printf("\nActu %p ", pelem);
		printf("Top %p ", pelem->top);
		printf("Prev %p ", pelem->prev);
		printf("Next %p ", pelem->next);
		printf("bot %p", pelem->bot);
		pelem = pelem->prev;
	}
}

static int	set_content_to_map(struct s_map *map, int content, struct s_core *core)
{
	static int exit = 0;
	static int player = 0;

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
}

static int setup_map_struct_value(struct s_core *core, struct s_three_int *three_int, int content)
{
	struct s_map *nouv = malloc(sizeof(*nouv));
	if(!nouv)
		return (0);
	nouv->map_value.x = three_int->x;
	nouv->map_value.y = three_int->y;
	nouv->map_value.content = content;
	nouv->map_value.acces = 1;
	//et si entoure ennemis ?
	if (set_content_to_map(nouv, content, core) == 0)
		return (0);
	nouv->prev = (*core).last;
	nouv->next = NULL;
	nouv->bot = NULL;
	if (three_int->y == 0)
		nouv->top = NULL;
	else
		set_tb_struct(nouv, three_int->size);
	if((*core).last)
		(*core).last->next = nouv;
	else
		(*core).first = nouv;
	(*core).last = nouv;
	return (1);
}

static int	check_map_validity(int fd, int i, struct s_core *core, struct s_three_int *three_int)
{
	char	*line;

	while ((line = get_next_line(fd)) != 0)
	{
		while (line[i] && line[i] != '\n')
		{
			if (setup_map_struct_value(core, three_int, line[i]) == 0)
				return (0);
			three_int->x++;
			i++;
		}
		if (three_int->size == 0)
			three_int->size = three_int->x;
		else if (three_int->size != three_int->x)
			return (print_enum_msg(ERROR_MAP));
		three_int->x = 0;
		three_int->y++;
		i = 0;
	}
	core->last->next = NULL;
	core->last->bot = NULL;
	if (set_content_to_map(NULL, 'Z', core) == 0)
		return (0);
	return (1);
}

void	map_loader(char *file, struct s_core *core)
{
	int	fd;
	t_three_int	three_int;

	setup_struct_value(core, &three_int);
	check_ber(file);
	fd = open(file, O_RDONLY);
	fd = check_map_validity(fd, 0, core, &three_int);
	if (fd != 1)
		exit(0);
	test_parcour(core);
	core->mlx = mlx_init(three_int.size, three_int.y, "test", false);
}
