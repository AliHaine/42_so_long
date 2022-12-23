#include "../so_long.h"

void	free_map(struct s_dblist *map)
{
	t_map *to_free = map->first;

	while (to_free)
	{
		if (to_free->next != NULL)
		{
			to_free = to_free->next;
			free(to_free->prev);
		}
		else
		{
			free(to_free);
			return ;
		}
	}
}
