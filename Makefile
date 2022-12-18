NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS =	so_long.c \
		srcs/msg_manager.c \
		srcs/map_manager.c
INC	= -I ../MLX42/include
MINILIBX = ../MLX42/libmlx42.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" 

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} $(INC) -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
