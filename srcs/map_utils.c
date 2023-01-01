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

bool	is_wall(struct s_map *map)
{
	if (map->bot == NULL)
		return (true);
	else if (map->top == NULL)
		return (true);
	else if (map->prev->map_value.y != map->map_value.y)
		return (true);
	else if (map->next->map_value.y != map->map_value.y)
		return (true);
	return (false);
}

bool	can_goto(int c)
{
	if (c == '1' || c == 'B')
		return (false);
	return (true);
}
