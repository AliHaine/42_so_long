/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:03:43 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:03:49 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	set_content_to_map(t_map *map, int co, t_core *core, t_three_int *t)
{
	t_player	*p;

	if (co == '0' || co == '1'
		|| co == 'E' || co == 'M' || co == 'P')
	{
		setup_struct_value(map, t->x, t->y, co);
		map->map_value.acces = 1;
		if (co == 'P')
		{
			p = malloc(sizeof(*p));
			if (p == NULL)
				return (0);
			core->pos = p;
			core->pos->map = map;
			core->pos->map->map_value.content = 'P';
			core->pos->dir = 1;
		}
		else if (co == 'E')
			core->exit = map;
		else if (co == '0')
			map->map_value.acces = 0;
	}
	else
		return (print_enum_msg(ERROR_MAP));
	return (check_content(co, core));
}

static int	setup_map_sval(struct s_core *core, struct s_three_int *ti, int c)
{
	struct s_map	*nouv;

	nouv = malloc(sizeof(*nouv));
	if (!nouv)
		return (0);
	if (c != 'C')
	{
		if (set_content_to_map(nouv, c, core, ti) == 0)
			return (0);
	}
	else
	{
		setup_struct_value(nouv, ti->x, ti->y, c);
		core->consumable++;
	}
	nouv->prev = (*core).last;
	nouv->next = NULL;
	nouv->bot = NULL;
	if (check_wall(nouv, ti, ti->x + 1) == 0)
		free_struct(core);
	if (ti->y == 0)
		nouv->top = NULL;
	else
		set_tb_struct(nouv, ti->size);
	if ((*core).last)
		(*core).last->next = nouv;
	else
		(*core).first = nouv;
	(*core).last = nouv;
	return (1);
}

static int	check_map_val(int fd, int i, t_core *core, t_three_int *ti)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[i] && line[i] != '\n')
		{
			if (setup_map_sval(core, ti, line[i]) == 0)
				return (0);
			ti->x++;
			i++;
		}
		if (ti->size == 0)
			ti->size = ti->x;
		else if (ti->size != ti->x)
			return (print_enum_msg(ERROR_MAP));
		ti->x = 0;
		ti->y++;
		i = 0;
	}
	if (check_content('Z', core) == 0 || check_content('T', core) == 0)
		return (0);
	return (1);
}

void	map_loader(char *file, struct s_core *core)
{
	int			fd;
	t_three_int	three_int;

	core->first = NULL;
	core->last = NULL;
	core->pos = NULL;
	core->exit = NULL;
	core->consumable = 0;
	three_int.x = 0;
	three_int.y = 0;
	three_int.size = 0;
	check_ber(file);
	fd = open(file, O_RDONLY);
	fd = check_map_val(fd, 0, core, &three_int);
	if (fd != 1)
		free_struct(core);
	check_flood_fill(core);
	core->last->next = NULL;
	core->last->bot = NULL;
	core->mlx = mlx_init(three_int.size * S, three_int.y * S, "test", true);
}
