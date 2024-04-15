/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:23:09 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 10:23:12 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *msg, t_game *game, int exit_time)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (exit_time == 1)
	{
		if (game->texture)
			free(game->texture);
		free(game);
		exit(EXIT_FAILURE);
	}
	if (game)
	{
		if (game->map.full)
			data_clear(game, 0);
		else
		{
			if (game->texture)
				free(game->texture);
			free(game);
		}
	}
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nThis programe take 1 arg .ber", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error\nFailed to allocate memory,game", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	game->texture = malloc(sizeof(t_texture));
	if (!game->texture)
	{
		ft_putstr_fd("Error\nFailed to allocate memory,texture", STDERR_FILENO);
		free(game);
		return (EXIT_FAILURE);
	}
	init_game(game, argv[1]);
	load_game(game);
}

void	put_all_textures(t_texture *texture, t_game *game)
{
	put_backgrounds(texture, game);
	put_walls(texture, game);
	put_collectibles(texture, game);
	put_exit(texture, game);
	put_player(texture, game);
}

void	load_textures(t_texture *texture, t_game *game)
{
	int	x;
	int	y;

	texture->wall = mlx_png_file_to_image(game->mlx,
			"./assets/textures/background/wall.png", &x, &y);
	texture->collectible = mlx_png_file_to_image(game->mlx,
			"./assets/textures/treasure/collectible.png", &x, &y);
	texture->exit = mlx_png_file_to_image(game->mlx,
			"./assets/textures/exit/exit.png", &x, &y);
	texture->player = mlx_png_file_to_image(game->mlx,
			"./assets/textures/player/player.png", &x, &y);
	texture->background = mlx_png_file_to_image(game->mlx,
			"./assets/textures/background/flatsize.png", &x, &y);
}

void	load_game(t_game *game)
{
	int	x;

	x = 90;
	more_verif(game);
	parse_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map.columns
			* x, game->map.rows * x, "");
	initialize_img(game, game->texture);
	mlx_on_event(game->mlx, game->win, MLX_KEYDOWN, key_hook, game);
	mlx_on_event(game->mlx, game->win, MLX_WINDOW_EVENT, window_hook, game);
	mlx_loop(game->mlx);
	error_message("", game, 0);
}
