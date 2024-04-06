/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:17:22 by vgodart           #+#    #+#             */
/*   Updated: 2024/02/15 12:17:23 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_destroy(t_game *game)
{
	int	i;

	if (game)
	{
		i = 0;
		if (game != 0 && game->map.full != 0)
		{
			while (i < game->map.rows)
			{
				free(game->map.full[i]);
				i++;
			}
			free(game->map.full);
		}
	}
}

void	data_clear(t_game *game, int exit_time)
{
	if (game && exit_time == 0)
	{
		if (game->texture)
		{
			if (game->texture->collectible)
				mlx_destroy_image(game->mlx, game->texture->collectible);
			if (game->texture->exit)
				mlx_destroy_image(game->mlx, game->texture->exit);
			if (game->texture->player)
				mlx_destroy_image(game->mlx, game->texture->player);
			if (game->texture->background)
				mlx_destroy_image(game->mlx, game->texture->background);
			if (game->texture->wall)
				mlx_destroy_image(game->mlx, game->texture->wall);
			free(game->texture);
		}
		if (game->win && game->mlx)
		{
			mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
		}
		if (game->map.full)
			game_destroy(game);
		free(game);
	}
}
