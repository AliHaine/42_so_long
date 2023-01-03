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
# include <stdbool.h>

# define S 64
# define WALL "./assets/deco/g.png"
# define GROUND "./assets/deco/w.png"
# define BLOC "./assets/deco/gb.png"
# define BLOC1 "./assets/deco/gb1.png"
# define BLOC2 "./assets/deco/gb2.png"
# define BITEM "./assets/items/g_i.png"
# define P_G "./assets/characters/p_01.png"
# define P_GA "./assets/characters/p_a3.png"
# define P_D "./assets/characters/p_0.png"
# define P_DA "./assets/characters/p_a2.png"

typedef enum MSG
{
	ERROR,
	ERROR_ARGS_NUMBER,
	ERROR_MAP,
	ERROR_PLAYER_TOHIGH,
	ERROR_NO_PLAYER,
	ERROR_EXIT_TOHIGH,
	ERROR_NO_EXIT,
	ERROR_NO_WALL,
	ERROR_EXIT_ACCESS,
	ERROR_CONSUM_ACCESS
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
	struct s_map_value	mv;
	struct s_map		*prev;
	struct s_map		*next;
	struct s_map		*top;
	struct s_map		*bot;
}	t_map;

typedef struct s_player
{
	struct s_map		*map;
	int					movenbr;
	int					item;
	int					dir;
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
	mlx_image_t		*txt;
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
void	check_ber(const char *file);
int		check_wall(struct s_map *map, struct s_three_int *three_int, int x);
int		check_content(int content, struct s_core *core);
void	free_struct(struct s_core *core);
void	key_event(mlx_key_data_t key_data, void *core);
void	loop_event(void *core);
void	set_tb_struct(struct s_map *map, int size);
void	setup_struct_value(struct s_map *map, int x, int y, int c);
void	game_loader(struct s_core *core);
void	my_sleep(double nb);
void	move_event(struct s_core *core);
void	hit_event(struct s_core *core);
bool	is_wall(struct s_map *map);
void	load_and_disp_img(mlx_t *mlx, t_map_value *mv, char *path, int c);
void	i_or_c_action(struct s_core *core, struct s_map_value *mv);
bool	can_goto(int c);
bool	check_exit(struct s_core *core);
char	*ft_itoa(unsigned int nb);

#endif
