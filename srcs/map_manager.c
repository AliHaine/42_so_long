#include "../so_long.h"

void test_parcour(t_map *s)
{
	(void)s;
	printf("next = %p\n", (s)->next);
	printf("actu = %p\n", (s));
	printf("prec = %p\n", (s)->prev->prev);
	//printf("d = %d", s->prev->x);
	/*while (s)
	{
		printf("t2");
		if (s->prev == NULL)
			break ;
		s = s->prev;
	}*/

	/*while(!s->next)
	{
		printf("x = %d", s->x);
		printf("y = %d", s->y);
		s = s->next;
	}*/
}

static t_map*	setup_map_struct(char c, int x, int y, t_map **prev)
{
	(void)c;
	t_map *tile;

	tile = malloc(sizeof(tile));
	if (tile == 0)
		return (0);
	if (!*prev)
	{
		tile->prev = NULL;
	}
	else
	{
		tile->prev = *prev;
		//prev->next = tile;
	}
	//printf("x = %d", x);
	//printf("y = %d\n", y);
	tile->x = x;
	tile->y = y;
	tile->content = 0;
	return (tile);
}

static int	check_map_validity(int fd)
{
	//int		size;
	(void)fd;
	int		i;
	int		x;
	int 	y;
	t_map	*prev;
	char	line[] = "salut je test";

	i = 0;
	x = 0;
	y = 0;
	prev = 0;
	//line = get_next_line(fd);
	while (1 + 1 == 2)
	{
		if (prev != NULL)
			printf("before prec = %p\n", (prev)->prev);
		while (line[i] && line[i] != '\n')
		{
			if (i > 0)
				printf("start prec = %p\n", (prev)->prev);
			prev = setup_map_struct(line[i], x, y, &prev);
			if (!prev)
				return (0);
			x++;
			i++;
		}
		i = 0;
		y++;
		x = 0;
		printf("precEnd = %p\n", (prev));
		test_parcour(prev);
		break;

//		printf("next = %p\n", prev->next);
		printf("precEnd = %p\n", (prev)->prev);
		printf("precEnd = %p\n", (prev)->prev);
	}
	printf("\nResult = %p\n", (prev)->prev);
	//printf("x = %d", x);
	//printf("y = %d", y);
	prev->next = NULL;
	//test_parcour(&prev);
	return (1);
}

static void	check_ber(char *file)
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

void	map_loader(char *file)
{
	int	fd;
	check_ber(file);

	fd = open(file, O_RDONLY);
	check_map_validity(fd);
}
