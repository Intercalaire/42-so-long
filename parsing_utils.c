/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:29:17 by vgodart           #+#    #+#             */
/*   Updated: 2024/03/13 17:29:30 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*collectiblesy(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	*positions;

	positions = malloc((game->map.columns * game->map.rows) * sizeof(int));
	if (!positions)
		error_message("Error\nparsing failed", game, 0);
	i = 0;
	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == COLLECTIBLE)
				positions[i++] = y;
			x++;
		}
		y++;
	}
	return (positions);
}

int	*collectiblesx(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	*positions;

	positions = malloc(game->map.columns * game->map.rows * sizeof(int));
	i = 0;
	if (!positions)
		error_message("Error\nparsing failed", game, 0);
	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == COLLECTIBLE)
				positions[i++] = x;
			x++;
		}
		y++;
	}
	return (positions);
}

int	exitx(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == EXIT)
				game->map.exit_pos.x = x;
			x++;
		}
		y++;
	}
	return (game->map.exit_pos.x);
}

int	exity(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == EXIT)
				game->map.exit_pos.y = y;
			x++;
		}
		y++;
	}
	return (game->map.exit_pos.y);
}
