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
	if (!img && printf("%s\n", file_path))
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
