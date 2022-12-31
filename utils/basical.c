/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:05:06 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:05:07 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_sleep(double nb)
{
	int	i;

	i = 0;
	while (i < nb * 50000000)
		i++;
}

static int	check_content_pe(int content)
{
	static int	exit = 0;
	static int	player = 0;

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
	t_map	*mc;

	if (content == '0' || content == '1' || content == 'X' || content == 'M')
		return (1);
	else if (content == 'C')
		core->consumable++;
	else if (content == 'E' || content == 'P' || content == 'Z')
		return (check_content_pe(content));
	else if (content == 'T')
	{
		mc = core->last;
		while (mc->bot == NULL)
		{
			if (mc->map_value.content != '1')
				return (print_enum_msg(ERROR_NO_WALL));
			mc = mc->prev;
		}
	}
	else
		return (print_enum_msg(ERROR_MAP));
	return (1);
}

int	check_wall(struct s_map *map, struct s_three_int *three_int, int x)
{
	if (three_int->y == 0)
	{
		if (map->map_value.content != '1')
			return (print_enum_msg(ERROR_NO_WALL));
	}
	else if (three_int->x == 0 && map->prev->map_value.y != map->map_value.y)
	{
		if (map->map_value.content != '1')
			return (print_enum_msg(ERROR_NO_WALL));
	}
	else if (x == three_int->size)
	{
		if (map->map_value.content != '1')
			return (print_enum_msg(ERROR_NO_WALL));
	}
	return (1);
}

void	check_ber(const char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return ;
	print_enum_msg(ERROR_MAP);
	exit(0);
}
