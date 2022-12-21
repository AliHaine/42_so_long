#include "../so_long.h"

void test_parcour(t_dblist *s)
{
	printf("//%p//", s->first);
	t_map *pelem = s->first;
	while(pelem)
	{
		printf("%p", pelem);
		printf(" %c", pelem->map_value.content);
		printf(" %d", pelem->map_value.x);
		printf(" %d\n", pelem->map_value.y);
		pelem = pelem->next;
	}
}

/*static void start_mlx(mlx_t mlx, t_dblist map)
{

}*/

static int	set_content_to_map(struct s_map *map, int content, struct s_dblist ****controler)
{
	if (content == '0')
	{
		/*mlx_load_png("../assets/forest_v1.3/forest_.png");
		map->map_value.content = '0';
		map->map_value.img = mlx_new_image(controler->mlx, 128, 128);
		map->map_value.texture = mlx_load_png("../assets/forest_v1.3/forest_.png");
		mlx_image_to_window(controler->mlx, mlx_texture_to_image(controler->mlx, map->map_value.texture), 0, 0);*/
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
		(****controler).pos = map;
		map->map_value.content = 'P';
	}
	else
	{
		print_enum_msg(ERROR_MAP);
		return (0);
	}
	return (1);
}

static void setup_map_struct(struct s_dblist ***map, struct s_three_int *three_int, int content)
{

	struct s_map *nouv = malloc(sizeof(nouv));
	if(!nouv)
		return ;
	nouv->map_value.x = three_int->x;
	nouv->map_value.y = three_int->y;
	if (set_content_to_map(nouv, content, &map) == 0)
	{
		free_map(&map);
		exit (0);
	}
	nouv->map_value.content = content;
	nouv->prev = (***map).last;
	nouv->next = NULL;
	if((***map).last)
		(***map).last->next = nouv;
	else
		(***map).first = nouv;
	(***map).last = nouv;
	printf("Actu %p", nouv);
	printf(" Next %p", nouv->next);
	printf(" Prec %p\n", nouv->prev);
	printf("last %p", (***map).last);
	printf("first %p\n\n", (***map).first);
}

static void	setup_struct_value(t_dblist **map, t_three_int *three_int)
{
	(*map)->first = NULL;
	(*map)->last = NULL;
	three_int->x = 0;
	three_int->y = 0;
	three_int->size = 0;
}

static int	check_map_validity(int fd, int i, struct s_dblist **map, struct s_three_int *three_int)
{
	char	*line;

	while ((line = get_next_line(fd)) != 0)
	{
		while (line[i] && line[i] != '\n')
		{
			setup_map_struct(&map, three_int, line[i]);
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
	(**map).last->next = NULL;
	//***mlx = mlx_init(three_int.size * 100, three_int.y * 100, "test", true);
	return (1);
}

void	map_loader(char *file, struct s_dblist *map)
{
	int	fd;
	t_three_int	three_int;

	setup_struct_value(&map, &three_int);
	check_ber(file);
	fd = open(file, O_RDONLY);
	fd = check_map_validity(fd, 0, &map, &three_int);
	printf("salut %p", map->last);
	printf("salut %p\n", map->first);
	test_parcour(map);
	map->mlx = mlx_init(three_int.size * 64, three_int.y * 64, "test", true);
	if (fd != 1)
		exit(0);
}
