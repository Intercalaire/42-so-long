/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:23:25 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 10:23:26 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_utils(t_game *game, char *file_name);

void	init_game(t_game *game, char *file_name)
{
	game->map.collectible = 0;
	game->map.exit = 0;
	game->win = 0;
	game->mlx = 0;
	game->map.player = 0;
	game->position.x = 0;
	game->position.y = 0;
	game->player_up = 0;
	game->player_down = 0;
	game->player_left = 0;
	game->player_right = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->player_move = 0;
	game->exit_replace = 0;
	init_game_utils(game, file_name);
}

static void	init_game_utils(t_game *game, char *file_name)
{
	game->map.player_pos.x = 0;
	game->map.player_pos.y = 0;
	game->map.exit_pos.x = 0;
	game->map.exit_pos.y = 0;
	game->map.collectible_pos.x = 0;
	game->map.collectible_pos.y = 0;
	game->map.full = NULL;
	game->map.full = init_map(game, file_name);
	game->map.columns = ft_strlen(game->map.full[0]) - 1;
	game->map.rows = columns_count(game, file_name);
	game->texture->player = 0;
	game->texture->wall = 0;
	game->texture->collectible = 0;
	game->texture->exit = 0;
	game->texture->background = 0;
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 22)
		ft_player_move(game, playery(game) + 1, playerx(game));
	if (key == 7)
		ft_player_move(game, playery(game), playerx(game) + 1);
	if (key == 4)
		ft_player_move(game, playery(game), playerx(game) - 1);
	if (key == 26)
		ft_player_move(game, playery(game) - 1, playerx(game));
	if (key == ESC)
		mlx_loop_end(game->mlx);
	return (0);
}

int	window_hook(int event, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (event == 0)
		mlx_loop_end(game->mlx);
	return (0);
}

void	initialize_img(t_game *game, t_texture *texture)
{
	verif_image(game);
	load_textures(texture, game);
	put_all_textures(texture, game);
}
