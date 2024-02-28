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

int	move_up(t_game *game)
{
	if (game->map.full[game->map.player_pos.y / 90 - 1][game->map.player_pos.x / 90] == WALL ||
	(game->map.full[game->map.player_pos.y / 90 - 1][game->map.player_pos.x / 90] == EXIT
	&& game->map.collectible != 0))
		return (0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture->background,
		game->map.player_pos.x, game->map.player_pos.y);
	game->map.player_pos.y -= 90;
	game->player_move++;
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == COLLECTIBLE)
	{
		game->map.collectible--;
		game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] = EMPTY;
	}
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == EXIT)
	{
		if (game->map.collectible == 0)
			data_clear(game);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->player, game->map.player_pos.x, game->map.player_pos.y);
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map.full[game->map.player_pos.y / 90 + 1][game->map.player_pos.x / 90] == WALL ||
	(game->map.full[game->map.player_pos.y / 90 + 1][game->map.player_pos.x / 90] == EXIT
		&& game->map.collectible != 0))
		return (0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->background, game->map.player_pos.x, game->map.player_pos.y);
	game->map.player_pos.y += 90;
	game->player_move++;
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == COLLECTIBLE)
	{
		game->map.collectible--;
		game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] = EMPTY;
	}
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == EXIT)
	{
		if (game->map.collectible == 0)
			data_clear(game);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->player, game->map.player_pos.x + 1, game->map.player_pos.y + 1);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90 - 1] == WALL ||
	(game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90 - 1] == EXIT
	&& game->map.collectible != 0))
		return (0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->background, game->map.player_pos.x, game->map.player_pos.y);
	game->map.player_pos.x -= 90;
	game->player_move++;
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == COLLECTIBLE)
	{
		game->map.collectible--;
		game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] = EMPTY;
	}
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == EXIT)
	{
		if (game->map.collectible == 0)
			data_clear(game);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->player, game->map.player_pos.x, game->map.player_pos.y);
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90 + 1] == WALL ||
	(game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90 + 1] == EXIT &&
	game->map.collectible != 0))
		return (0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->background, game->map.player_pos.x, game->map.player_pos.y);
	game->map.player_pos.x += 90;
	game->player_move++;
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == COLLECTIBLE)
	{
		game->map.collectible--;
		game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] = EMPTY;
	}
	if (game->map.full[game->map.player_pos.y / 90][game->map.player_pos.x / 90] == EXIT)
	{
		if (game->map.collectible == 0)
			data_clear(game);
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->texture->player, game->map.player_pos.x, game->map.player_pos.y);
	return (0);
}