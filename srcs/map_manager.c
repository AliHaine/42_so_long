#include "../so_long.h"

void test_parcour(t_dblist s)
{
	t_map *pelem = s.first;
	while(pelem)
	{
		printf("%p", pelem);
		printf(" %c", pelem->map_value.content);
		printf(" %d", pelem->map_value.x);
		printf(" %d\n", pelem->map_value.y);
		pelem = pelem->next;
	}
}

static int	set_content_to_map(struct s_map *map, int content)
{
	if (content == '0')
	{
		map->map_value.content = '0';
	}
	else if (content == '1')
	{
		map->map_value.content = '0';
	}
	else if (content == 'C')
	{
		map->map_value.content = 'C';
	}
	else if (content == 'E')
	{
		map->map_value.content = 'E';
	}
	else if (content == 'P')
	{
		map->map_value.content = 'P';
	}
	else
	{
		print_enum_msg(ERROR_MAP);
		return (0);
	}
	return (1);
}

static void setup_map_struct(struct s_dblist *map, struct s_three_int three_int, int content)
{
	struct s_map *nouv = malloc(sizeof(nouv));
	if(!nouv)
		return ;
	nouv->map_value.x = three_int.x;
	nouv->map_value.y = three_int.y;
	if (set_content_to_map(nouv, content) == 0)
	{
		free_map(*map);
		exit (0);
	}
	nouv->map_value.content = content;
	nouv->prev = map->last;
	nouv->next = NULL;
	if(map->last)
		map->last->next = nouv;
	else
		map->first = nouv;
	map->last = nouv;
}

static void	setup_struct_value(t_dblist *map, t_three_int *three_int)
{
	map->first = NULL;
	map->last = NULL;
	three_int->x = 0;
	three_int->y = 0;
	three_int->size = 0;
}

static int	check_map_validity(int fd, int i, char * line)
{
	t_dblist	map;
	t_three_int	three_int;

	setup_struct_value(&map, &three_int);
	while ((line = get_next_line(fd)) != 0)
	{
		while (line[i] && line[i] != '\n')
		{
			setup_map_struct(&map, three_int, line[i]);
			three_int.x++;
			i++;
		}
		if (three_int.size == 0)
			three_int.size = three_int.x;
		else if (three_int.size != three_int.x)
			return (print_enum_msg(ERROR_MAP));
		three_int.x = 0;
		three_int.y++;
		i = 0;
	}
	map.last->next = NULL;
	test_parcour(map);
	return (1);
}

void	map_loader(char *file)
{
	int	fd;
	char *str;

	str = NULL;

	check_ber(file);
	fd = open(file, O_RDONLY);
	fd = check_map_validity(fd, 0, str);
	if (fd != 1)
		exit(0);
}
