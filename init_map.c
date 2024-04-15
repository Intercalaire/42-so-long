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

static int	row_count(t_game *game, char *file_name, int old_fd);

static int	extension_file(t_game *game, char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.');
	if (!extension || ft_strlen(extension) != 4)
	{
		error_message("Error\nInvalid map, not a .ber file", game, 0);
		return (1);
	}
	if ((extension[0] == '.') && (extension[1] == 'b') && (extension[2] == 'e')
		&& (extension[3] == 'r'))
		return (0);
	error_message("Error\nInvalid map, not a .ber file", game, 1);
	return (1);
}

char	**init_map(t_game *game, char *file_name)
{
	int				fd;
	unsigned int	len_line;
	char			**map;

	if (game == NULL || file_name == NULL)
		error_message("Error\ngame or game->map is NULL", game, 1);
	extension_file(game, file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 1);
	game->map.full = (char **)
		ft_calloc(sizeof(char *), (columns_count(game, file_name) + 1));
	if (!game->map.full)
	{
		close(fd);
		error_message("Error\nFailed to allocate memory for game", game, 1);
	}
	len_line = row_count(game, file_name, fd);
	map = init_map_utils(game, fd, len_line);
	close(fd);
	return (map);
}

static int	row_count(t_game *game, char *file_name, int old_fd)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 1);
	i = 0;
	line = get_next_line(fd);
	if (!line || !line[0] || line[0] == EOF)
	{
		close(fd);
		close(old_fd);
		free(line);
		exit_map_utils(fd, line, game, "Error\nEmpty line");
	}
	while (line[i])
		i++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	columns_count(t_game *game, char *file_name)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 1);
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

int	how_many_inside(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == PLAYER)
			game->map.player++;
		else if (line[i] == EXIT)
			game->map.exit++;
		else if (line[i] == COLLECTIBLE)
			game->map.collectible++;
		else if (line[i] != WALL && line[i] != EMPTY && line[i] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
