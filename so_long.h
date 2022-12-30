/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:20:49 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:20:52 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "utils/get_next_line/get_next_line.h"
# define S 64

typedef enum MSG
{
	ERROR,
	ERROR_ARGS_NUMBER,
	ERROR_MAP,
	ERROR_PLAYER_TOHIGH,
	ERROR_NO_PLAYER,
	ERROR_EXIT_TOHIGH,
	ERROR_NO_EXIT,
	ERROR_NO_WALL
}	t_msg;

typedef struct s_map_value
{
	short			exit;
	int				content;
	int				x;
	int				y;
	short			acces;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}	t_map_value;

typedef struct s_map
{
	struct s_map_value	map_value;
	struct s_map		*prev;
	struct s_map		*next;
	struct s_map		*top;
	struct s_map		*bot;
}	t_map;

typedef struct s_player
{
	struct s_map		*map;
	int 				movenbr;
	int 				dir;
	mlx_image_t			*img;
	mlx_texture_t		*texture;
}	t_player;

typedef struct s_core
{
	mlx_t			*mlx;
	struct s_map	*first;
	struct s_map	*last;
	struct s_map	*exit;
	struct s_player	*pos;
	int				consumable;
}	t_core;

typedef struct s_three_int
{
	int	x;
	int	y;
	int	size;
}	t_three_int;

int		ft_putstr(char *str);
int		print_enum_msg(enum MSG id);
void	map_loader(char *file, struct s_core *map);
void	check_ber(char *file);
int		check_wall(struct s_map *map, struct s_three_int *three_int, int x);
int		check_content(int content, struct s_core *core);
void	free_struct(struct s_core *core);
void	key_event(mlx_key_data_t key_data, void *core);
void	loop_event(void *core);
void	set_tb_struct(struct s_map *map, int size);
void	setup_struct_value(struct s_map *map, int x, int y, int c);
void	game_loader(struct s_core *core);
void	load_img(void *mv, mlx_t *mlx);
void	my_sleep(double nb);
void	move_event(struct s_core *core);

#endif
