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

static void	ft_move(t_game *game, int new_y, int new_x);

void	ft_player_move(t_game *game, int new_y, int new_x)
{
	int			last_x;
	int			last_y;

	last_x = game->map.player_pos.x;
	last_y = game->map.player_pos.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.collectible == 0)
		error_message("you have win", game, 0);
	game->map.full[last_y][last_x] = EMPTY;
	if ((game->map.full[new_y][new_x] == EMPTY)
		|| (game->map.full[new_y][new_x] == COLLECTIBLE))
	{
		if (game->map.full[new_y][new_x] == COLLECTIBLE)
			game->map.collectible--;
		if (game->exit_replace == 1)
		{
			game->map.full[last_y][last_x] = EXIT;
			game->exit_replace = 0;
		}
		ft_move(game, new_y, new_x);
	}
	else if (game->map.full[new_y][new_x] == EXIT && game->exit_replace == 0)
	{
		game->exit_replace = 1;
		ft_move(game, new_y, new_x);
	}
}

static void	ft_move(t_game *game, int new_y, int new_x)
{
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	game->map.full[new_y][new_x] = PLAYER;
	game->player_move++;
	ft_printf("steps = %d\n", game->player_move);
	put_all_textures(game->texture, game);
}

int	playerx(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.player_pos.x = x;
			}
			x++;
		}
		y++;
	}
	return (game->map.player_pos.x);
}

int	playery(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.player_pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (game->map.player_pos.y);
}
