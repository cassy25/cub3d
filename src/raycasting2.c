/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:38:52 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/12 13:14:36 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_raycasting(t_data *data)
{
	int	x;

	x = 0;
	data->ray.x = data->posx;
	data->ray.y = data->posy;
	render_background(data);
	while (x < WIDTH)
	{
		raycasting(data, x);
		raycasting2(data);
		dist_wall(data);
		draw_wall(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->wdw, data->img.mlx_img, 0, 0);
	return (0);
}

void	draw_wall(t_data *data, int x)
{
	int			color;
	t_drawtex	wall;
	t_img		tex;

	tex = ft_wall_tex(data);
	wall = ft_tex_coordinates(data, tex);
	while (data->ray.start_line < data->ray.end_line)
	{
		wall.texy = (int)wall.texpos & (tex.y - 1);
		wall.texpos += wall.step;
		color = img_pix_color(tex, wall.texx, wall.texpos);
		img_pix_put(data->img, x, data->ray.start_line, color);
		data->ray.start_line++;
	}
}

t_drawtex	ft_tex_coordinates(t_data *data, t_img tex)
{
	t_drawtex	wall;

	if (data->ray.side == 0)
		wall.wallx = data->posy + data->ray.wall_dist * data->ray.ray_diry;
	else
		wall.wallx = data->posx + data->ray.wall_dist * data->ray.ray_dirx;
	wall.wallx -= floor(wall.wallx);
	wall.texx = (int)(wall.wallx * (double)tex.x);
	if (data->ray.side == 0 && data->ray.ray_dirx > 0)
		wall.texx = tex.x - wall.texx - 1;
	if (data->ray.side == 1 && data->ray.ray_diry < 0)
		wall.texx = tex.x - wall.texx - 1;
	wall.step = (float)tex.y / (float)data->ray.line_height;
	wall.texpos = (((float)data->ray.start_line - ((float)HEIGHT / 2)
				+ ((float)data->ray.line_height / 2)) * wall.step);
	return (wall);
}

t_img	ft_wall_tex(t_data *data)
{
	if (data->ray.side == 1 && data->ray.stepy < 0)
		return (data->no);
	else if (data->ray.side == 0 && data->ray.stepx < 0)
		return (data->we);
	else if (data->ray.side == 0 && data->ray.stepx >= 0)
		return (data->ea);
	else
		return (data->so);
}
