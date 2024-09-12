/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:31:04 by kenito            #+#    #+#             */
/*   Updated: 2023/12/19 22:31:04 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_map(t_game *game, int fd)
{
	char *(line) = get_next_line(fd);
	if (!line)
		error_message(game, "cannot read map.");
	char *(new_line) = get_next_line(fd);
	while (new_line)
	{
		line = join_n_free(line, new_line);
		free(new_line);
		if (!line)
			error_message(game, "Failed to allocate memory.");
		new_line = get_next_line(fd);
	}
	line = remove_char(line, '\r');
	game->map = ft_split(line, '\n');
	free(line);
	if (!game->map)
		error_message(game, "Failed to allocate memory.");
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = (int)ft_strlen(game->map[0]);
	find_cordinate(game->map, 'E', &game->exit_x, &game->exit_y);
	game->collectibles = count_char(game->map, 'C');
	return (check_map(game));
}

char	*remove_char(char *str, char c)
{
	int (i) = 0;
	int (j) = 0;
	while (str[i])
		if (str[i++] != c)
			j++;
	char *(new_str) = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_str)
		error_message(NULL, "Failed to allocate memory.");
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

int	find_cordinate(char **map, char c, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == c)
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	printf("Error\n%c is not found.\n", c);
	return (1);
}

int	free_map(char **map)
{
	int (i) = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int	print_map(char **map)
{
	int i;
	int j;
	i = -1;
	while (map[++i]){
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
	return (0);
}