/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sprites.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kenito <kenito@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/30 00:44:12 by kenito			#+#	#+#			 */
/*   Updated: 2024/06/30 00:44:12 by kenito		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_hiroshi(t_game *game, t_chara *chara)
{
	find_cordinate(game->map, 'P', &chara->x, &chara->y);
	chara->dir = DOWN;
	chara->animation = 0;
	chara->front[0] = xpm_alpha(game, "sprites/hiroshi/front_0.xpm");
	chara->back[0] = xpm_alpha(game, "sprites/hiroshi/back_0.xpm");
	chara->left[0] = xpm_alpha(game, "sprites/hiroshi/left_0.xpm");
	chara->right[0] = xpm_alpha(game, "sprites/hiroshi/right_0.xpm");
	chara->front[1] = xpm_alpha(game, "sprites/hiroshi/front_1.xpm");
	chara->back[1] = xpm_alpha(game, "sprites/hiroshi/back_1.xpm");
	chara->left[1] = xpm_alpha(game, "sprites/hiroshi/left_1.xpm");
	chara->right[1] = xpm_alpha(game, "sprites/hiroshi/right_1.xpm");
	return (0);
}

int	init_aooni(t_game *game, t_chara *aooni)
{
	find_cordinate(game->map, 'E', &aooni->x, &aooni->y);
	aooni->dir = DOWN;
	aooni->animation = 0;
	aooni->front[0] = xpm_alpha(game, "sprites/aooni/front_0.xpm");
	aooni->back[0] = xpm_alpha(game, "sprites/aooni/back_0.xpm");
	aooni->left[0] = xpm_alpha(game, "sprites/aooni/left_0.xpm");
	aooni->right[0] = xpm_alpha(game, "sprites/aooni/right_0.xpm");
	aooni->front[1] = xpm_alpha(game, "sprites/aooni/front_1.xpm");
	aooni->back[1] = xpm_alpha(game, "sprites/aooni/back_1.xpm");
	aooni->left[1] = xpm_alpha(game, "sprites/aooni/left_1.xpm");
	aooni->right[1] = xpm_alpha(game, "sprites/aooni/right_1.xpm");
	return (0);
}

int	init_sprite(t_game *game)
{
	game->sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!game->sprite)
		error_message(game, "Failed to allocate memory.");
	game->sprite->exit = xpm_alpha(game, "sprites/exit.xpm");
	game->sprite->floor = xpm_alpha(game, "sprites/floor.xpm");
	game->sprite->wall = xpm_alpha(game, "sprites/wall.xpm");
	game->sprite->collect[0] = xpm_alpha(game, "sprites/collect_0.xpm");
	game->sprite->collect[1] = xpm_alpha(game, "sprites/collect_1.xpm");
	game->sprite->collect[2] = xpm_alpha(game, "sprites/collect_2.xpm");
	game->sprite->collect[3] = xpm_alpha(game, "sprites/collect_3.xpm");
	return (0);
}

int	free_sprite(t_game *game)
{
	int (i) = 0;
	mlx_destroy_image(game->mlx, game->sprite->exit);
	mlx_destroy_image(game->mlx, game->sprite->floor);
	mlx_destroy_image(game->mlx, game->sprite->wall);
	while (i < 4)
		mlx_destroy_image(game->mlx, game->sprite->collect[i++]);
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
