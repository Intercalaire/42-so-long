/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:42:46 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 11:42:48 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rows(t_game *game);
static void	check_columns(t_game *game);
static void	verification_cep(t_game *game);

void	more_verif(t_game *game)
{
	check_rows(game);
	check_columns(game);
	verification_cep(game);
}

static void	check_rows(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		if (game->map.full[y][0] != WALL)
		{
			error_message("Error\nThe Map no surrounded by walls on the left",
				game, 0);
		}
		else if (game->map.full[y][game->map.columns - 1] != WALL)
		{
			error_message("Error\nThe Map no surrounded by walls on the right",
				game, 0);
		}
		y++;
	}
}

static void	check_columns(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map.columns)
	{
		if (game->map.full[0][x] != WALL)
		{
			error_message("Error\nThe Map no surrounded by walls on the top",
				game, 0);
		}
		else if (game->map.full[game->map.rows - 1][x] != WALL)
		{
			error_message("Error\nThe Map no surrounded by walls on the bottom",
				game, 0);
		}
		x++;
	}
}

static void	verification_cep(t_game *game)
{
	if (game->map.collectible == 0)
	{
		error_message("Error\nto low collectible", game, 0);
	}
	else if (game->map.exit != 1)
	{
		error_message("Error\nthere is no one exit", game, 0);
	}
	else if (game->map.player != 1)
	{
		error_message("Error\nthere is one player", game, 0);
	}
}
