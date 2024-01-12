/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:52:29 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/08 14:04:23 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_d(t_data *data)
{
	if (data->map[(int)(data->posy + data->ray.dir_x * data->move_speed)]
		[(int)(data->posx - data->ray.dir_y * data->move_speed)] != '1')
	{
		data->posx -= data->ray.dir_y * data->move_speed;
		data->posy += data->ray.dir_x * data->move_speed;
	}
}

void	key_s(t_data *data)
{
	if (data->map[(int)(data->posy - data->ray.dir_y * data->move_speed)]
		[(int)(data->posx - data->ray.dir_x * data->move_speed)] != '1')
	{
		data->posx -= data->ray.dir_x * data->move_speed;
		data->posy -= data->ray.dir_y * data->move_speed;
	}
}

void	key_a(t_data *data)
{
	if (data->map[(int)(data->posy - data->ray.dir_x * data->move_speed)]
		[(int)(data->posx + data->ray.dir_y * data->move_speed)] != '1')
	{
		data->posx += data->ray.dir_y * data->move_speed;
		data->posy -= data->ray.dir_x * data->move_speed;
	}
}

void	key_w(t_data *data)
{
	if (data->map[(int)(data->posy + data->ray.dir_y * data->move_speed)]
		[(int)(data->posx + data->ray.dir_x * data->move_speed)] != '1')
	{
		data->posx += data->ray.dir_x * data->move_speed;
		data->posy += data->ray.dir_y * data->move_speed;
	}
}
