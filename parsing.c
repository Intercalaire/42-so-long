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

static	void	init_visited(t_game *game, char **visited);

static void	deep_search(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| visited[y][x] || game->map.full[y][x] == WALL
		|| game->map.full[y][x] == EXIT)
		return ;
	visited[y][x] = WALL;
	deep_search(game, x + 1, y, visited);
	deep_search(game, x, y + 1, visited);
	deep_search(game, x, y - 1, visited);
	deep_search(game, x - 1, y, visited);
}

static void	free_visited(char **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	parse_map(t_game *game)
{
	char		**visited;
	int			i;

	visited = malloc((game->map.rows * game->map.columns) * sizeof(char *));
	if (!visited)
		error_message("Error\nparsing failed", game, 0);
	i = 0;
	while (i < game->map.rows)
	{
		visited[i] = ft_calloc(game->map.columns, sizeof(char *));
		if (!visited[i])
			error_message("Error\nparsing failed", game, 0);
		i++;
	}
	init_visited(game, visited);
}

static	void	init_visited(t_game *game, char **visited)
{
	int	i;
	int	*tabx;
	int	*taby;

	deep_search(game, playerx(game), playery(game), visited);
	i = 0;
	taby = collectiblesy(game);
	tabx = collectiblesx(game);
	game->map.exit_pos.y = exity(game);
	game->map.exit_pos.x = exitx(game);
	while (i < game->map.collectible)
	{
		if (!visited[taby[i]][tabx[i]])
		{
			free(tabx);
			free(taby);
			free_visited(visited, game);
			error_message("Error\nparsing failed", game, 0);
		}
		i++;
	}
	free(tabx);
	free(taby);
	free_visited(visited, game);
}
