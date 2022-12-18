#include "../so_long.h"

void test_parcour(map_s *s)
{
	printf("t1");
	printf("d = %d", s->prev->prev->prev->x);
	int i = 0;
	while (i < 0)
	{
		printf("t2");
		s = s->prev;
		i++;
	}/*
	while(!s->next)
	{
		printf("x = %d", s->x);
		printf("y = %d", s->y);
		s = s->next;
	}*/
}

static map_s*	setup_map_struct(char c, int x, int y, map_s *prev)
{
	(void)c;
	map_s *tile;

	tile = malloc(sizeof(tile));
	if (tile == 0)
		return (0);
	if (prev == 0)
	{
		tile->prev = NULL;
	}
	else
	{
		tile->prev = prev;
		prev->next = tile;
	}

	tile->x = x;
	tile->y = y;
	tile->content = 0;
	return (tile);
}

static int	check_map_validity(int fd)
{
	//int		size;
	int		i;
	int		x;
	int 	y;
	map_s	*prev;
	char	*line;

	i = 0;
	x = 0;
	y = 0;
	while ((line = get_next_line(fd)) != 0)
	{
		while (line[i] && line[i] != '\n')
		{
			prev = setup_map_struct(line[i], x, y, prev);
			x++;
			i++;
		}
		i = 0;
		y++;
		x = 0;
	}
	//printf("salut %d", prev->x);
	test_parcour(prev);
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
