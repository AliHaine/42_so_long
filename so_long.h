
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "utils/get_next_line/get_next_line.h"

typedef enum MSG
{
	ERROR,
	ERROR_ARGS_NUMBER,
	ERROR_MAP
} msg;

typedef struct s_map_value
{
	short	exit;
	int		content;
	int		x;
	int		y;
	short	acces;
	mlx_image_t	*img;
	mlx_texture_t *texture;
} t_map_value;

typedef struct s_map
{
	struct s_map_value map_value;
	struct s_map *prev;
	struct s_map *next;
} t_map;

typedef struct s_dblist
{
	mlx_t		*mlx;
	struct s_map *first;
	struct s_map *last;
	struct s_map *pos;
} t_dblist;

typedef struct s_three_int
{
	int x;
	int y;
	int size;
} t_three_int;

int		ft_strchr(const char *str, int strchar);
int		ft_putstr(char *str);
int		print_enum_msg(enum MSG id);
void	map_loader(char *file, struct s_dblist *map);
void	check_ber(char *file);
void	free_map(struct s_dblist ****map);

#endif
