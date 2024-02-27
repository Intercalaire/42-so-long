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
	if (game->map.player_pos.x != x || game->map.player_pos.y != y)
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
		if (game->map.collectible_pos[k].x == game->map.player_pos.x
			&& game->map.collectible_pos[k].y == game->map.player_pos.y)
		{
			game->map.collectible_pos[k].x = -1;
			game->map.collectible_pos[k].y = -1;
			game->map.collectible++;
		}
		k++;
	}
}

void	move_player(t_game *game)
{
	int				x;
	int				y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
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
	if (game->map.exit_pos.x == game->map.player_pos.x
		&& game->map.exit_pos.y == game->map.player_pos.y)
		if (game->map.collectible == game->map.player_coll)
			error_message("fin", game);
}