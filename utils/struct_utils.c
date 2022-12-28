/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:05:22 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:05:23 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_tb_struct(struct s_map *map, int size)
{
	t_map	*iterator;

	iterator = map;
	while (size--)
		iterator = iterator->prev;
	map->top = iterator;
	iterator->bot = map;
}

void	setup_struct_value(struct s_map *map, int x, int y, int c)
{
	map->map_value.x = x;
	map->map_value.y = y;
	map->map_value.content = c;
	map->map_value.acces = 1;
}

void	free_struct(struct s_core *core)
{
	t_map	*m;

	m = core->first;
	while (m)
	{
		if (m->next != NULL)
		{
			m = m->next;
			free (m->prev);
		}
		else
			break ;
	}
	free(m);
	exit(0);
}
