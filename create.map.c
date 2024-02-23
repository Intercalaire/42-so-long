/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:24:19 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/20 11:24:21 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_create(t_game *game)
{
	int	x;

	x = 0;
	game->map.full = malloc(sizeof(char *) * game->map.rows);
	if (!game->map.full)
		return (1);
	while (x < game->map.rows)
	{
		game->map.full[x] = malloc(sizeof(char) * game->map.columns);
		if (!game->map.full[x])
			return (1);
		x++;
	}
	return (0);
}
