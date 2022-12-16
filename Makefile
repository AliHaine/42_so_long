NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS =	so_long.c
MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean