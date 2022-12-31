/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:26:16 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/30 23:26:18 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_exit(struct s_core *core)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = core->pos->map->map_value.x;
	x2 = core->exit->map_value.x;
	y1 = core->pos->map->map_value.y;
	y2 = core->exit->map_value.y;
	if (core->consumable == 0)
		if (x1 == x2 && y1 == y2)
			return (true);
	return (false);
}

void	check_flood_fill(struct s_core *core)
{
	int		c;
	int		e;
	t_map	*flood;

	c = 0;
	e = 0;
	flood = core->first;
	while (flood)
	{
		if (flood->map_value.content == 'C')
			c++;
		else if (flood->map_value.content == 'E')
			e++;
		flood = flood->next;
	}
	if (c != core->consumable)
	{
		print_enum_msg(ERROR_CONSUM_ACCESS);
		exit(1);
	}
	if (e != 1)
	{
		print_enum_msg(ERROR_EXIT_ACCESS);
		exit(1);
	}
}