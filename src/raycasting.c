/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:07:39 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/08 13:51:22 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data, int x)
{
	//Calcul de la direction du rayon
	data->ray.camera_x = 2 * x / (double)WIDTH - 1;
	data->ray.ray_dirx = data->ray.dir_x + data->ray.plane_x
		* data->ray.camera_x;
	data->ray.ray_diry = data->ray.dir_y + data->ray.plane_y
		* data->ray.camera_x;
	// Position initiale du rayon
	data->ray.mapx = (int)data->posx;
	data->ray.mapy = (int)data->posy;
	// Calcul des distances entre les intersections du rayon
	data->ray.delta_distx = fabs(1 / data->ray.ray_dirx);
	data->ray.delta_disty = fabs(1 / data->ray.ray_diry);
	data->ray.collision = 0;
	if (data->ray.ray_dirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.side_distx = (data->posx - data->ray.mapx)
			* data->ray.delta_distx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.side_distx = (data->ray.mapx + 1.0 - data->posx)
			* data->ray.delta_distx;
	}
}

//suite pour determiner la direction du rayon
void	raycasting2(t_data *data)
{
	if (data->ray.ray_diry < 0)
	{
		data->ray.stepy = -1;
		data->ray.side_disty = (data->posy - data->ray.mapy)
			* data->ray.delta_disty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.side_disty = (data->ray.mapy + 1.0 - data->posy)
			* data->ray.delta_disty;
	}
	collision_wall(data);
}

//Faire une condition pour verifier la collision avec un mur
void	collision_wall(t_data *data)
{
	while (data->ray.collision == 0)
	{
		if (data->ray.side_distx >= data->ray.side_disty)
		{
			data->ray.side_disty += data->ray.delta_disty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		else
		{
			data->ray.side_distx += data->ray.delta_distx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		if (data->map[(int)data->ray.mapy][(int)data->ray.mapx] == '1')
			data->ray.collision = 1;
	}
}

//Calculer la distance perpendiculaire au mur puis avoir les 
// coordonnees pour dessiner a la bonne hauteur
void	dist_wall(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_dist = (data->ray.side_distx - data->ray.delta_distx);
	else
		data->ray.wall_dist = (data->ray.side_disty - data->ray.delta_disty);
	if (data->ray.wall_dist)
		data->ray.line_height = (int)(HEIGHT / data->ray.wall_dist);
	else
		data->ray.line_height = (int)HEIGHT * 2;
	data->ray.start_line = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.start_line < 0)
		data->ray.start_line = 0;
	data->ray.end_line = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.end_line >= HEIGHT)
		data->ray.end_line = HEIGHT - 1;
}
