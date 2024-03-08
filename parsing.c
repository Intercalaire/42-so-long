/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:07:06 by vgodart           #+#    #+#             */
/*   Updated: 2024/03/04 14:07:08 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_game *game)
{
    char **visited;
    int i;

    visited = malloc(game->map.columns);
    if (i < game->map.columns)
    {
        visited[i] = ft_calloc(game->map.rows, sizeof(char));
        i++;
    }
    deep_search(game, playerx(game), playery(game), visited);
    i = 0;
    while (i < game->map.rows)
    {
        if (!visited[game->map.full[i].y])
    }
}