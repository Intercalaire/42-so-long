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

void	ft_player_move(t_game *game)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player_pos.x;
	last_y = game->map.player_pos.y;
	if (game->map.full[0][0] == EXIT && game->map.collectible == 0)
		data_clear(game);
	else if ((game->map.full[0][0] == EMPTY)
	|| (game->map.full[0][0] == COLLECTIBLE))
	{
		game->map.full[last_y][last_x] = EMPTY;
		if (game->map.full[0][0] == COLLECTIBLE)
			game->map.collectible--;
		game->map.player_pos.x += 2;
		game->map.player_pos.y = 0;
		game->player_move++;
        put_all_textures(game->texture, game);
	}
}


int key_hook(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    ft_printf("steps = %d\n", game->player_move);
    if(key == 22)
        ft_player_move(game);
    if(key == 4)
        ft_player_move(game);
    if(key == 7)
        ft_player_move(game);
    if(key == 26)
       ft_player_move(game);
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
