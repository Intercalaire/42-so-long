/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:16 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/15 13:38:18 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*initialiser la map, */

/*look the extention_file if this is a .ber*/
int extension_file(t_game *game, char *file_name)
{
	char *extension;
	extension = ft_strrchr(file_name, '.');

	if (!extension || ft_strlen(extension) != 4)
	{
		error_message("Error\nInvalid map, not a .ber file", game);
		return (1);
	}
	if ((extension[0] == '.') && (extension[1] == 'b') && (extension[2] == 'e') && (extension[3] == 'r'))
	{
		return (0);
	}
	error_message("Error\nInvalid map, not a .ber file", game);
	return (1);
}

char **init_map(t_game *game, char *file_name)
{
	int fd;
	unsigned int len_line;
	char *line;
	int i;

	if (game == NULL || file_name == NULL)
		error_message("Error\ngame or game->map is NULL", game);
	extension_file(game, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message("Error\nFailed to open file", game);
	game->map.full = (char **)malloc(sizeof(char *) * (columns_count(game, file_name) + 1));
	if (!game->map.full)
		return (0);
	len_line = row_count(game, file_name);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (ft_strlen(line) != len_line)
		{
			error_message("Error\nnot rectangulare", game);
		}
		if (line[0] == '\n')
		{
			error_message("Error\nInvalid map, empty line", game);
		}
		how_many_inside(game, line);
		game->map.full[i] = ft_strdup(line);
		i++;
		free(line);
	}
	game->map.full[i] = NULL;
	close(fd);
	return (game->map.full);
}

int row_count(t_game *game, char *file_name)
{
	int count;
	int fd;
	char *line;
	int i;

	fd = open(file_name, O_RDONLY);
	count = 0;
	i = 0;
	line = get_next_line(fd);
	if (fd == -1)
	{
		error_message("Error\nFailed to open file", game);
	}
	while(line[i])
	{
		i++;
		count++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

int columns_count(t_game *game, char *file_name)
{
	int count;
	int fd;
	char *line;

	fd = open(file_name, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	if (fd == -1)
	{
		error_message("Error\nFailed to open file", game);
	}
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

void how_many_inside(t_game *game, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == Player)
			game->map.player++;
		if (line[i] == EXIT)
			game->map.exit++;
		if (line[i] == COLLECTIBLE)
			game->map.collectible++;
		i++;
	}
}
