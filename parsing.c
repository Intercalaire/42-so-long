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
/*
int	parse_map(t_game *game)
{
	int x;
    int y;
    int count_two;
    int i = 0;
    char    **copie_full;

    copie_full = game->map.full;
    x = playerx(game);
    y = playery(game);
    count_two = 0;
    while(i != 5)
    {
        if (copie_full[y][x + 1] == EMPTY)
        {
            x++;
            copie_full[y][x] = '2';
            count_two++;
            ft_printf("%c", copie_full[y][x]);
        }
        if (copie_full[y + 1][x] == EMPTY)
        {
            y++;
            copie_full[y][x] = '2';
            count_two++;
            ft_printf("%c", copie_full[y][x]);
        }

        i++;
    }
    if (count_two != game->map.wall)
        error_message("Error\nparsing", game);
    return (0);
}*/