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

static	void	init_visit(t_game *game, char **visited, int *tabx, int *taby);
static void	free_tab(int *tab_a, int *tab_b);

static void	deep_search(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= game->map.columns || y >= game->map.rows
		|| visited[y][x] || game->map.full[y][x] == WALL)
		return ;
	visited[y][x] = WALL;
	deep_search(game, x + 1, y, visited);
	deep_search(game, x, y + 1, visited);
	deep_search(game, x, y - 1, visited);
	deep_search(game, x - 1, y, visited);
}

static void	free_visit(char **visited, t_game *game)
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
	char	**visited;
	int		i;
	int		*tabx;
	int		*taby;

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
	taby = collectiblesy(game);
	tabx = collectiblesx(game);
	init_visit(game, visited, tabx, taby);
}

static	void	init_visit(t_game *game, char **visited, int *tabx, int *taby)
{
	int	i;

	i = 0;
	deep_search(game, playerx(game), playery(game), visited);
	game->map.exit_pos.y = exity(game);
	game->map.exit_pos.x = exitx(game);
	while (i < game->map.collectible)
	{
		if (!visited[taby[i]][tabx[i]])
		{
			free_tab(tabx, taby);
			free_visit(visited, game);
			error_message("Error\nparsing failed", game, 0);
		}
		i++;
	}
	if (!visited[game->map.exit_pos.y][game->map.exit_pos.x])
	{
		free_tab(tabx, taby);
		free_visit(visited, game);
		error_message("Error\nparsing failed", game, 0);
	}
	free_tab(tabx, taby);
	free_visit(visited, game);
}

static void	free_tab(int *tab_a, int *tab_b)
{
	free(tab_a);
	free(tab_b);
}
