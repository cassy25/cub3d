/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:22:17 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/12/18 16:44:32 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	if (keysym == KEY_A)
		move_player_y(data, -1);
	if (keysym == KEY_S)
		move_player_y(data, 1);
	if (keysym == KEY_D)
		move_player_x(data, 1);
	if (keysym == KEY_W)
		move_player_x(data, -1);
	endgame(data);
	return (0);
}

int	move_player_y(t_data *game, int i)
{
	if (game->map[game->posY + i][game->posX] != '1')
	{
		game->posY += i;
		return (1);
	}
	return (0);
}

int	move_player_x(t_data *game, int i)
{
	if (game->map[game->posX + i][game->posY] != '1')
	{
		game->posX += i;
		return (1);
	}
	return (0);
}