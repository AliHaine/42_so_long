
#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libs/minilibx_opengl_20191021/mlx.h"
# include "utils/get_next_line/get_next_line.h"

char	*get_next_line(int fd);
int		ft_strchr(const char *str, int strchar);

#endif