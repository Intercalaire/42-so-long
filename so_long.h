/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:23:17 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/09 10:23:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MacroLibX/includes/mlx.h"
# include "Libft/libft.h"

# include <SDL2/SDL_scancode.h>

# include <stdlib.h>
# include <fcntl.h> 
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			collectible;
	int			exit;
	int			player;
	int			player_coll;
	t_position	player_pos;
	t_position	exit_pos;
	t_position	*collectible_pos;
	t_position	*position;
}	t_map;

typedef struct s_texture
{
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	void	*background;
}	t_texture;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*param;
	int key;
	int	player_up;
	int	player_down;
	int	player_left;
	int	player_right;
	int	player_move;
	int img_width;
	int img_height;
	t_position	position;
	t_map	map;
	t_texture			*texture;
}	t_game;

int key_hook(int key, void* param);
int window_hook(int event, void* param);
int image_moove(int key, void* param);
void	initialize_img(t_game *game, t_texture *texture);
void init_game(t_game *game, char *file_name);
void	verification_CEP(t_game *game);
void	check_rows(t_game *game);
void	check_columns(t_game *game);
void more_verif(t_game *game);
void	how_many_inside(t_game *game, char *line);
char	**init_map(t_game *game, char *file_name);
int	row_count(t_game *game, char *file_name);
void error_message(char *msg, t_game *game);
int extension_file(t_game *game, char *file_name);
void clear_map(t_game *game);
void	data_clear(t_game *game);
void	load_textures(t_texture *texture, t_game *game);
void	exit_game(t_game *game);
void	put_walls(t_texture *texture, t_game *game);
void	put_collectibles(t_texture *texture, t_game *game);
void	put_exit(t_texture *texture, t_game *game);
void	put_player(t_texture *texture, t_game *game);
void	put_backgrounds(t_texture *texture, t_game *game);
void	put_all_textures(t_texture *texture, t_game *game);
int columns_count(t_game *game, char *file_name);
void	ft_player_move(t_game *game, int new_y, int new_x);
int playerx(t_game *game);
int playery(t_game *game);


// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define ESC 41

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

//# define CELL_SIZE 32

#endif
