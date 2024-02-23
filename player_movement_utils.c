/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:09:57 by vgodart           #+#    #+#             */
/*   Updated: 2024/02/23 13:09:59 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	had_move(t_game *game, int x, int y)
{
	if (game->position.x != x || game->position.y != y)
	{
		game->player_move++;
		ft_putnbr_fd(game->player_move++, 1);
		ft_putendl_fd("", 1);
	}
}

static void	collect(t_game *game)
{
	int				k;

	k = 0;
	while (k < game->map.collectible)
	{
		if (game->map.collectible[k].x == game->position.x
			&& game->map.collectible[k].y == game->position.y)
		{
			game->map.collectible[k].x = -1;
			game->map.collectible[k].y = -1;
			game->map.collectible++;
		}
		k++;
	}
}

void	move_player (t_game *game)
{
	int				x;
	int				y;

	x = game->position.x;
	y = game->position.y;
	if (game->player_up != 0)
		move_up(game, x, y);
	else if (game->player_down != 0)
		move_down(game, x, y);
	else if (game->player_left != 0)
		move_left(game, x, y);
	else if (game->player_right != 0)
		move_right(game, x, y);
	had_move(game, x, y);
	collect(game);
	if (game->map->exit.x == game->position->x
		&& game->map->exit.y == game->position->y)
		if (game->map->collectible == game->map->coll)
			game_clear(game, 0, 0);
}