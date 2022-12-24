#include "../so_long.h"

void	free_map(struct s_core *core)
{
	t_map *to_free = core->first;

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

void	check_ber(char *file)
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