NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS =	so_long.c \
		srcs/msg_manager.c \
		srcs/map_manager.c \
		srcs/key_manager.c \
		srcs/game_manager.c \
		srcs/map_utils.c \
		srcs/event/move_event.c \
		srcs/event/hit_event.c \
		utils/basical.c \
		utils/struct_utils.c \
		utils/ft_itoa.c \
		utils/get_next_line/get_next_line.c \
		utils/get_next_line/get_next_line_utils.c
INC	= -I ../MLX42/include
MINILIBX = ../MLX42/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" 

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} $(INC) -g3 -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
