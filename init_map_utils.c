/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:10:17 by vgodart           #+#    #+#             */
/*   Updated: 2024/04/06 11:10:36 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_map_utils(int fd, char *line, t_game *game, char *msg)
{
	int	j;

	j = 0;
	while (game->map.full[j])
	{
		free(game->map.full[j]);
		j++;
	}
	free(game->map.full);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	free(game->texture);
	free(game);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	**init_map_utils(t_game *game, int fd, unsigned int len_line)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n' || !line[0] || line[0] == EOF)
			exit_map_utils(fd, line, game, "Error\nEmpty line");
		if ((ft_strlen(line) != len_line) && (len_line != 0))
			exit_map_utils(fd, line, game, "Error\nMap not rectangular");
		if (!how_many_inside(game, line))
			exit_map_utils(fd, line, game, "Error\nSign not recognized");
		game->map.full[i] = line;
		i++;
	}
	game->map.full[i] = NULL;
	return (game->map.full);
}

void	verif_image(t_game *game)
{
	int	fd;

	fd = open("./assets/textures/background/flatsize.png", O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 0);
	close(fd);
	fd = open("./assets/textures/background/wall.png", O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 0);
	close(fd);
	fd = open("./assets/textures/treasure/collectible.png", O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 0);
	close(fd);
	fd = open("./assets/textures/exit/exit.png", O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 0);
	close(fd);
	fd = open("./assets/textures/player/player.png", O_RDONLY);
	if (fd < 0 || fd > 1024)
		error_message("Error\nFailed to open file", game, 0);
	close(fd);
}
