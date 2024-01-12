/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:44:15 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/11 18:28:38 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor_ceiling(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
			&data->img.line, &data->img.endian);
	data->no.addr = mlx_get_data_addr(data->no.mlx_img, &data->no.bpp, \
			&data->no.line, &data->no.endian);
	data->so.addr = mlx_get_data_addr(data->so.mlx_img, &data->so.bpp, \
			&data->so.line, &data->so.endian);
	data->we.addr = mlx_get_data_addr(data->we.mlx_img, &data->we.bpp, \
			&data->we.line, &data->we.endian);
	data->ea.addr = mlx_get_data_addr(data->ea.mlx_img, &data->ea.bpp, \
			&data->ea.line, &data->ea.endian);
}

void	render_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(data->img, j++, i, data->c);
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img_pix_put(data->img, j++, i, data->f);
		i++;
	}
}

void	img_pix_put(t_img img, int x, int y, int color)
{
	char	*pixel;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		pixel = img.addr + (y * img.line + x * (img.bpp / 8));
		*(int *)pixel = color;
	}
}

int	img_pix_color(t_img img, int x, int y)
{
	if ((x >= 0 && x < img.x) && (y >= 0 && y < img.y))
		return (*(int *)(img.addr + 4 * img.y * y + 4 * x));
	return (0);
}
