/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:30:23 by kenito            #+#    #+#             */
/*   Updated: 2023/12/19 22:30:23 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	error_message(t_game *game, char *detail)
{
	ft_printf("Error: %s\n", detail);
	if (!game)
		exit(EXIT_FAILURE);
	if (game->map)
		free_map(game->map);
	if (game->sprite)
		free_sprite(game);
	if (game->hiroshi)
		free_chara(game, game->hiroshi);
	if (game->aooni)
		free_chara(game, game->aooni);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	free(game);
	exit(EXIT_FAILURE);
}

int	end_game(t_game *game, char *detail)
{
	if (game->map)
		free_map(game->map);
	if (game->sprite)
		free_sprite(game);
	if (game->hiroshi)
		free_chara(game, game->hiroshi);
	if (game->aooni)
		free_chara(game, game->aooni);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
	free(game);
	printf("%s\n", detail);
	exit(EXIT_SUCCESS);
}

t_game	*init_game(t_game *game, int fd)
{
	if (fd < 0)
		error_message(game, "File Not Found.");
	if (init_map(game, fd))
		error_message(game, "Invalid Map.");
	close(fd);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_message(game, "mlx_init() failed.");
	game->win = mlx_new_window(game->mlx, game->width * SIZE, (game->height + 2) * SIZE, "aooni");
	if (!game->win)
		error_message(game, "mlx_new_window() failed.");
	init_sprite(game);
	game->hiroshi = (t_chara *)malloc(sizeof(t_chara));
	if (!game->hiroshi)
		error_message(game, "Failed to allocate memory.");
	init_hiroshi(game, game->hiroshi);
	game->aooni = (t_chara *)malloc(sizeof(t_chara));
	if (!game->aooni)
		error_message(game, "Failed to allocate memory.");
	init_aooni(game, game->aooni);
	return (game);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_message(NULL, "Invalid Arguments.");
	t_game *(game) = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_message(game, "Failed to allocate memory.");
	game = init_game(game, open(argv[1], O_RDONLY));
	mlx_hook(game->win, 17, 0, end_game, (void *)game);
	mlx_key_hook(game->win, key_hook, (void *)game);
	mlx_loop_hook(game->mlx, update, (void *)game);
	mlx_loop(game->mlx);
}

void end(void)__attribute__((destructor));

void end(void)
{
    system("leaks so_long");
}

