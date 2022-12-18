
#ifndef SO_LONG_H
# define SO_LONG_H

typedef enum MSG
{
	ERROR,
	ERROR_ARGS_NUMBER,
	ERROR_MAP
} msg;

typedef struct map
{
	int x;
	int y;
	int content;
	struct map *prev;
	struct map *next;
} map_s;

# include "MLX42/MLX42.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "utils/get_next_line/get_next_line.h"

int		ft_strchr(const char *str, int strchar);
int		ft_putstr(char *str);
int		print_enum_msg(enum MSG id);
void	map_loader(char *file);

#endif
