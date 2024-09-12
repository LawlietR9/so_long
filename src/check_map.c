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

int	check_map(t_game *game)
{
	if (check_wall(game))
		return (1);
	if (count_char(game->map, 'P') != 1 || !count_char(game->map, 'C')
		|| count_char(game->map, 'E') != 1)
		return (1);
	char **(map) = copy_map(game);
	if (!map)
		error_message(game, "Failed to allocate memory.");
	int (x), (y);
	find_cordinate(game->map, 'P', &x, &y);
	explore_map(map, y, x);
	if (count_char(map, 'E') || count_char(map, 'C'))
		return (1);
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != game->width)
			return (1);
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (1);
		j = 0;
		if (i == 0 || i == game->height - 1)
			while (game->map[i][j])
				if (game->map[i][j++] != '1')
					return (1);
		i++;
	}
	return (0);
}

int	count_char(char **map, char c)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	num = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

char	**copy_map(t_game *game)
{
	char	**map_cp;
	int		i;
	int		j;

	map_cp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!map_cp)
		error_message(game, "Failed to allocate memory.");
	i = 0;
	while (i < game->height)
	{
		map_cp[i] = (char *)malloc(game->width + 1);
		if (!map_cp[i])
			error_message(game, "Failed to allocate memory.");
		j = 0;
		while (game->map[i][j])
		{
			map_cp[i][j] = game->map[i][j];
			j++;
		}
		map_cp[i][j] = '\0';
		i++;
	}
	map_cp[i] = NULL;
	return (map_cp);
}

void	explore_map(char **map, int i, int j)
{
	map[i][j] = '1';
	if (map[i + 1][j] != '1')
		explore_map(map, i + 1, j);
	if (map[i][j + 1] != '1')
		explore_map(map, i, j + 1);
	if (map[i - 1][j] != '1')
		explore_map(map, i - 1, j);
	if (map[i][j - 1] != '1')
		explore_map(map, i, j - 1);
}
