NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= $(wildcard srcs/*.c) $(wildcard ./*.c)
OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
			make -C ./mlx
			mv ./mlx/libmlx.a ./libmlx.a
			$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)

clean:
	make -C ./mlx clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf so_long libmlx.a

re: fclean all

.PHONY: all clean fclean re

