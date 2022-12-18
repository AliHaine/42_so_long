
#ifndef SO_LONG_H
# define SO_LONG_H

typedef enum MSG
{
	ERROR,
	ERROR_ARGS_NUMBER,
	ERROR_MAP
} msg;

# include "MLX42/MLX42.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strchr(const char *str, int strchar);
int		ft_putstr(char *str);
int		print_enum_msg(enum MSG id);
void	map_loader(char *file);

#endif
