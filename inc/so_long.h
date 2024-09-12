/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:33:28 by kenito            #+#    #+#             */
/*   Updated: 2023/12/19 22:33:28 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define SIZE 60
# define UP 2
# define DOWN 0
# define LEFT 1
# define RIGHT 3

enum e_keycode
{
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	RESET = 15,
	ESC = 65307
};

typedef struct s_sprite
{
	void	*exit;
	void	*floor;
	void	*wall;
	void	*collect[4];
}	t_sprite;

typedef struct s_chara
{
	int		x;
	int		y;
	int		dir;
	int		moves;
	int		animation;
	void	*front[4];
	void	*back[4];
	void	*left[4];
	void	*right[4];
}	t_chara;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	t_sprite	*sprite;
	t_chara	*hiroshi;
	t_chara	*aooni;

	int		frame;
	int		moves;
	int		height;
	int		width;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_game;

int		error_message(t_game *game, char *detail);
int		end_game(t_game *game, char *detail);

int		init_map(t_game *game, int fd);
char	*remove_char(char *str, char c);
int		find_cordinate(char **map, char c, int *x, int *y);
int		free_map(char **map);
int		print_map(char **map);

int		check_map(t_game *game);
int		check_wall(t_game *game);
int		count_char(char **map, char c);
char	**copy_map(t_game *game);
void	explore_map(char **map, int i, int j);

int		key_hook(int key, t_game *game);
int		key_press(int key, t_game *game);
int 	key_release(int key, t_game *game);

int 	move_down(t_game *game, t_chara *chara);
int 	move_left(t_game *game, t_chara *chara);
int 	move_right(t_game *game, t_chara *chara);
int 	move_up(t_game *game, t_chara *chara);
int		move_random(t_game *game, t_chara *chara);

void	*xpm_alpha(t_game *game, char *file_path);
int		init_sprite(t_game *game);
int		init_hiroshi(t_game *game, t_chara *chara);
int		init_aooni(t_game *game, t_chara *chara);
int 	free_sprite(t_game *game);
int		free_chara(t_game *game, t_chara *chara);

int		mlx_put(t_game *game, void *img, int x, int y);
int		put_map(t_game *game);
int		put_character(t_game *game, t_chara *chara);
int		put_aooni(t_game *game, t_chara *aooni);
int		update(t_game *game);

#endif