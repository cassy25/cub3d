/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:07:39 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/12/18 16:17:44 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray(t_data *data)
{
    data->ray.dir_X = 0;
    data->ray.dir_Y = 0;
}


int raycasting(t_data *data)
{
    //Calcul de la direction du rayon
    data->ray.camera_x = 2 * data->ray.x / (double)WIDTH - 1;
    data->ray.ray_dirX = data->ray.dir_X + data->ray.plane_X * data->ray.camera_x;
    data->ray.ray_dirY = data->ray.dir_Y + data->ray.plane_Y * data->ray.camera_x;

    // Position initiale du rayon
    data->ray.mapX = (int)data->ray.x;
    data->ray.mapY = (int)data->ray.y;
    

    // Calcul des distances entre les intersections du rayon
    //data->ray.delta_distX = sqrt(1 + (data->ray.ray_dirY * data->ray.ray_dirY) / (data->ray.ray_dirX * data->ray.ray_dirX));
    //data->ray.delta_distY = sqrt(1 + (data->ray.ray_dirX * data->ray.ray_dirX) / (data->ray.ray_dirY * data->ray.ray_dirY));
    data->ray.delta_distX = fabs(1 / data->ray.ray_dirX);
    data->ray.delta_distY = fabs(1 / data->ray.ray_dirY);

    if (data->ray.ray_dirX < 0)
    {
        data->ray.stepX = -1;
        data->ray.side_distX = (data->ray.camera_x - data->ray.mapX) * data->ray.delta_distX;
    }
    else
    {
        data->ray.stepX = 1;
        data->ray.side_distX = (data->ray.mapX + 1.0 - data->ray.x) * data->ray.delta_distX;
    }

    if (data->ray.ray_dirY < 0)
    {
        data->ray.stepY = -1;
        data->ray.side_distY = (data->ray.y - data->ray.mapY) * data->ray.delta_distY;
    }
    else
    {
        data->ray.stepY = 1;
        data->ray.side_distY = (data->ray.mapY + 1.0 - data->ray.y) * data->ray.delta_distY;
    }
    //Lancement du rayon
    int side = 0;
    while(!data->ray.hit)
    {
        if (data->ray.side_distX < data->ray.side_distY)
        {
            data->ray.side_distX += data->ray.delta_distX;
            data->ray.mapX += data->ray.stepX;
            side = 0;
        }
        else
        {
            data->ray.side_distY += data->ray.delta_distY;
            data->ray.mapY += data->ray.stepY;
            side = 1;
        }

        //Faire une condition pour verifier la collision avec un mur
        
    }
}
