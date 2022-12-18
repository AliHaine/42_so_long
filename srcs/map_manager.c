#include "../so_long.h"

int	is_map_valid()
{
	return (1);
}

static void	is_ber(char *file)
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
	is_ber(file);
}
