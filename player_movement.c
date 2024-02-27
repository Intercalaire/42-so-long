/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:14:19 by vgodart           #+#    #+#             */
/*   Updated: 2024/02/13 14:14:21 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game, int x, int y)
{
	if (game->map.full[y + 1][x] == 0)
		game->map.player_pos.y += 1;
}

void	move_up(t_game *game, int x, int y)
{
	if (game->map.full[y - 1][x] == 0)
		game->map.player_pos.y -= 1;
}

void	move_left(t_game *game, int x, int y)
{
	if (game->map.full[y][x - 1] == 0)
		game->map.player_pos.x -= 1;
}

void	move_right(t_game *game, int x, int y)
{
	if (game->map.full[y][x + 1] == 0)
		game->map.player_pos.x += 1;
}