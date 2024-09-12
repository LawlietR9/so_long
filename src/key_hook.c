/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:14:05 by kenito            #+#    #+#             */
/*   Updated: 2024/06/27 21:14:05 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int key_hook(int key, t_game *game)
{
    if (game->hiroshi->animation)
        return (0);
    if (key == ESC)
        end_game(game, "Game Stopped");
    if (key == KEY_DOWN)
        move_down(game, game->hiroshi);
    if (key == KEY_LEFT)
        move_left(game, game->hiroshi);
    if (key == KEY_RIGHT)
        move_right(game, game->hiroshi);
    if (key == KEY_UP)
        move_up(game, game->hiroshi);
    if (key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP)
        printf("Moves: %d\n", ++game->hiroshi->moves);
    return (0);
}
