/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:14:08 by kenito            #+#    #+#             */
/*   Updated: 2024/06/30 00:14:08 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	mlx_put(t_game *game, void *img, int x, int y)
{
	if (mlx_put_image_to_window(game->mlx, game->win, img, x, y))
		error_message(game, "mlx_put_image_to_window() failed.");
	return (0);
}

int	put_map(t_game *game)
{
	char	**(map) = game->map;
	int (i) = 0;
	int (j) = 0;
	while (map[i])
	{
	    j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				mlx_put(game, game->sprite->floor, j * SIZE, (i + 1) * SIZE);
			if (map[i][j] == '1' && map[i + 1] && map[i + 1][j] != '1')
				mlx_put(game, game->sprite->wall, j * SIZE, (i + 1) * SIZE - 40);
			if (map[i][j] == 'C')
				mlx_put(game, game->sprite->collect[game->frame / 60 % 4], j * SIZE, (i + 1) * SIZE);
			j++;
		}
		i++;
	}
	if (!game->collectibles)
		mlx_put(game, game->sprite->exit, game->exit_x * SIZE, (game->exit_y + 1) * SIZE);
	return (0);
}

int put_character(t_game *game, t_chara *chara)
{
	int frame = 60;
	static int (motion);
	float (anime_dif) = SIZE * (1 - (float)motion / frame) * chara->animation;
	if (chara->dir == LEFT)
		mlx_put(game, chara->left[motion * 2 / frame],
		chara->x * SIZE + 10 + anime_dif, chara->y * SIZE + 30);
	else if (chara->dir == UP)
		mlx_put(game, chara->back[motion * 2 / frame],
		chara->x * SIZE + 10, chara->y * SIZE + 30 + anime_dif);
	else if (chara->dir == RIGHT)
		mlx_put(game, chara->right[motion * 2 / frame],
		chara->x * SIZE + 10 - anime_dif, chara->y * SIZE + 30);
	else
		mlx_put(game, chara->front[motion * 2 / frame],
		chara->x * SIZE + 10, chara->y * SIZE + 30 - anime_dif);
	if (chara->animation && ++motion == frame)
	{
		chara->animation = 0;
		motion = 0;
	}
	return (0);
}

int put_aooni(t_game *game, t_chara *aooni)
{
    int frame = 120;
    static int motion;
    float anime_dif = SIZE * (1 - (float)motion / frame) * aooni->animation;

    move_random(game, aooni);
    if (aooni->dir == LEFT)
        mlx_put(game, aooni->left[motion * 2 / frame],
        aooni->x * SIZE - 10 + anime_dif, aooni->y * SIZE - 30);
    else if (aooni->dir == UP)
        mlx_put(game, aooni->back[motion * 2 / frame],
        aooni->x * SIZE - 10, aooni->y * SIZE - 30 + anime_dif);
    else if (aooni->dir == RIGHT)
        mlx_put(game, aooni->right[motion * 2 / frame],
        aooni->x * SIZE - 10 - anime_dif, aooni->y * SIZE - 30);
    else
        mlx_put(game, aooni->front[motion * 2 / frame],
        aooni->x * SIZE - 10, aooni->y * SIZE - 30 - anime_dif);
    if (aooni->animation && ++motion == frame)
    {
        aooni->animation = 0;
        motion = 0;
    }
    return (0);
}

int update(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    put_map(game);
	put_aooni(game, game->aooni);
    put_character(game, game->hiroshi);
    if (game->map[game->hiroshi->y][game->hiroshi->x] == 'C')
    {
        game->map[game->hiroshi->y][game->hiroshi->x] = '0';
        game->collectibles--;
    }
	if (game->hiroshi->x == game->aooni->x && game->hiroshi->y == game->aooni->y)
		end_game(game, "Game Over.");
    else if (game->map[game->hiroshi->y][game->hiroshi->x] == 'E' && !game->collectibles)
        end_game(game, "Game Clear");
    game->frame++;
    return (0);
}
