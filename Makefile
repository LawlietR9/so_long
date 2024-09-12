NAME = so_long
SRC_FILES = check_map.c key_hook.c init_map.c so_long.c sprites.c update.c moves.c utils.c
SRC = $(addprefix src/,$(SRC_FILES)) 
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix obj/,$(OBJ_FILES)) $(GNL_SRCS:.c=.o)
LIBFT =  libft/libft.a
LIBFTPRINF = ft_printf/libftprintf.a
GNL_SRCS = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = $(LIBFT) $(LIBFTPRINF) $(MLX)
RM = rm -rf
UNAME_S := $(shell uname -s)
FSANITIZE = -g -fsanitize=address

ifeq ($(UNAME_S),Linux)
	MLX = -L/minilibx-linux -lmlx -lXext -lX11 -lm
else
	MLX = -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE) -g

obj/%.o: src/%.c
	make -C libft
	make -C ft_printf
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(OBJ) obj

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all