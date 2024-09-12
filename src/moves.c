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

int move_down(t_game *game, t_chara *chara)
{
    chara->dir = DOWN;
    if (chara->animation || game->map[chara->y + 1][chara->x] == '1')
        return (0);
    chara->animation = 1;
    chara->y++;
    return (0);
}

int move_left(t_game *game, t_chara *chara)
{
    chara->dir = LEFT;
    if (chara->animation || game->map[chara->y][chara->x - 1] == '1')
        return (0);
    chara->animation = 1;
    chara->x--;
    return (0);
}

int move_right(t_game *game, t_chara *chara)
{
    chara->dir = RIGHT;
    if (chara->animation || game->map[chara->y][chara->x + 1] == '1')
        return (0);
    chara->animation = 1;
    chara->x++;
    return (0);
}

int move_up(t_game *game, t_chara *chara)
{
    chara->dir = UP;
    if (chara->animation || game->map[chara->y - 1][chara->x] == '1')
        return (0);
    chara->animation = 1;
    chara->y--;
    return (0);
}

# include <stdlib.h>
# include <time.h>

int move_random(t_game *game, t_chara *aooni)
{
    int direction;

    if (aooni->animation)
        return (0);
    srand(time(NULL));
    direction = rand() % 4;
    if (direction == DOWN)
        move_down(game, aooni);
    else if (direction == LEFT)
        move_left(game, aooni);
    else if (direction == RIGHT)
        move_right(game, aooni);
    else
        move_up(game, aooni);
    return (0);
}
