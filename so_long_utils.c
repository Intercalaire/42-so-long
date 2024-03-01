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

void init_game(t_game *game, char *file_name)
{
    game->map.collectible = 0;
    game->map.exit = 0;
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
    game->map.player_pos.x = 0;
    game->map.player_pos.y = 0;
    game->map.full = init_map(game, file_name);
    game->map.columns = ft_strlen(game->map.full[0]) - 1;
    game->map.rows = columns_count(game, file_name);
    game->win = 0;
    game->mlx = 0;

}

void	ft_player_move(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player_pos.x;
	last_y = game->map.player_pos.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.collectible == 0)
		data_clear(game);
	else if ((game->map.full[new_y][new_x] == EMPTY)
	|| (game->map.full[new_y][new_x] == COLLECTIBLE))
	{
		game->map.full[last_y][last_x] = EMPTY;
		if (game->map.full[new_y][new_x] == COLLECTIBLE)
			game->map.collectible--;
		game->map.player_pos.x = new_x;
		game->map.player_pos.y = new_y;
		game->player_move++;
        put_player(game->texture, game);
	}
}


int key_hook(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if(key == 22)
    {
        ft_printf("steps = %d\n", game->player_move);
        ft_player_move(game, playery(game) + 1, playerx(game));
    }
    if(key == 4)
    {
        ft_printf("steps = %d\n", game->player_move);
        ft_player_move(game, playery(game), playerx(game) + 1);
    }
    if(key == 7)
    {
        ft_printf("steps = %d\n", game->player_move);
        ft_player_move(game, playery(game), playerx(game) - 1);
    }
    if(key == 26)
    {
        ft_printf("steps = %d\n", game->player_move);
        ft_player_move(game, playery(game) - 1, playerx(game));
    }
    if(key == ESC)
        mlx_loop_end(param);
    return (0);
}

/*0 is when we trigger the close of the window (by clicking the cross for example)*/
int window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end(param);
    return (0);
}

void	initialize_img(t_game *game, t_texture *texture)
{
    load_textures(texture, game);
    put_all_textures(texture, game);
}

int playerx(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == PLAYER)
			{
                ft_printf("|%d|", x);
				game->map.player_pos.x = x;
			}
			x++;
		}
		y++;
	}
    return (game->map.player_pos.x);
}

int playery(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.full[y])
	{
		x = 0;
		while (game->map.full[y][x])
		{
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.player_pos.y = y;
			}
			x++;
		}
		y++;
	}
    return (game->map.player_pos.y);
}