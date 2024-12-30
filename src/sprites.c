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

void	*xpm_alpha(t_game *game, char *file_path)
{
	int (width), height, bpp, size_l, endian;
	void *(img) = mlx_xpm_file_to_image(game->mlx, file_path, &width, &height);
	if (!img)
		error_message(game, "Failed to load image.");
	int *(data) = (int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);
	int (x), y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (data[y * width + x] == 0x000000)
				data[y * width + x] = 0xFF000000;
			x++;
		}
		y++;
	}
	return (img);
}

int	init_hiroshi(t_game *game, t_chara *chara)
{
	find_cordinate(game->map, 'P', &chara->x, &chara->y);
	chara->dir = DOWN;
	chara->animation = 0;
	chara->moves = 0;
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
	aooni->moves = 0;
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
