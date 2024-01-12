/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:22:17 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/08 14:05:22 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_player(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_destroy_data(data, 1);
	if (keysym == KEY_D)
	{
		key_d(data);
	}
	if (keysym == KEY_S)
	{
		key_s(data);
	}
	if (keysym == KEY_A)
	{
		key_a(data);
	}
	if (keysym == KEY_W)
	{
		key_w(data);
	}
	else
		move_camera(keysym, data);
	return (0);
}

int	move_camera(int keysym, t_data *data)
{
	data->ray.old_dir_x = data->ray.dir_x;
	data->ray.old_plane_x = data->ray.plane_x;
	if (keysym == KEY_LEFT)
	{
		data->ray.dir_x = data->ray.dir_x * cos(-data->rot_speed)
			- data->ray.dir_y * sin(-data->rot_speed);
		data->ray.dir_y = data->ray.old_dir_x * sin(-data->rot_speed)
			+ data->ray.dir_y * cos(-data->rot_speed);
		data->ray.plane_x = data->ray.plane_x * cos(-data->rot_speed)
			- data->ray.plane_y * sin(-data->rot_speed);
		data->ray.plane_y = data->ray.old_plane_x * sin(-data->rot_speed)
			+ data->ray.plane_y * cos(-data->rot_speed);
	}
	if (keysym == KEY_RIGHT)
	{
		data->ray.dir_x = data->ray.dir_x * cos(data->rot_speed)
			- data->ray.dir_y * sin(data->rot_speed);
		data->ray.dir_y = data->ray.old_dir_x * sin(data->rot_speed)
			+ data->ray.dir_y * cos(data->rot_speed);
		data->ray.plane_x = data->ray.plane_x * cos(data->rot_speed)
			- data->ray.plane_y * sin(data->rot_speed);
		data->ray.plane_y = data->ray.old_plane_x * sin(data->rot_speed)
			+ data->ray.plane_y * cos(data->rot_speed);
	}
	return (0);
}
