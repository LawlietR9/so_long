/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:24:57 by kenito            #+#    #+#             */
/*   Updated: 2023/12/29 22:38:13 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	free_map(char **map)
{
	int (i) = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	free_sprite(t_game *game)
{
	int (i) = 0;
	mlx_destroy_image(game->mlx, game->sprite->exit);
	mlx_destroy_image(game->mlx, game->sprite->floor);
	mlx_destroy_image(game->mlx, game->sprite->wall);
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->sprite->collect[i]);
		i++;
	}
	free(game->sprite);
	return (0);
}

int	free_chara(t_game *game, t_chara *chara)
{
	int (i) = 0;
	while (i < 2)
	{
		mlx_destroy_image(game->mlx, chara->front[i]);
		mlx_destroy_image(game->mlx, chara->back[i]);
		mlx_destroy_image(game->mlx, chara->left[i]);
		mlx_destroy_image(game->mlx, chara->right[i]);
		i++;
	}
	free(chara);
	return (0);
}
