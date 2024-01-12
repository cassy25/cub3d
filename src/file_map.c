/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:07:42 by roroca            #+#    #+#             */
/*   Updated: 2024/01/09 14:48:06 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	complete_line(t_data *data, int l, char *s)
{
	int	i;

	i = 0;
	data->map[l] = malloc(sizeof(char) * (data->sizemapx + 1));
	while (s[i] && s[i] != '\n')
	{
		data->map[l][i] = s[i];
		i++;
	}
	while (i < data->sizemapx)
		data->map[l][i++] = ' ';
	data->map[l][i] = 0;
	free(s);
}

void	player_pos(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->sizemapy)
	{
		player_pos2(data, y);
		y++;
	}
	if (check_map_wall(data, 'N') == 1 || check_map_wall(data, 'S') == 1
		|| check_map_wall(data, 'E') == 1 || check_map_wall(data, 'W') == 1)
	{
		printf("Error : Player out of bounds\n");
		ft_destroy_data(data, 0);
	}
	init_ray(data, data->map[(int)data->posy][(int)data->posx]);
}

void	player_pos2(t_data *data, int y)
{
	if (ft_strchrint(data->map[y], 'N') != -1)
	{
		data->posx = ft_strchrint(data->map[y], 'N') + 0.5;
		data->posy = y + 0.5;
	}
	if (ft_strchrint(data->map[y], 'W') != -1)
	{
		data->posx = ft_strchrint(data->map[y], 'W') + 0.5;
		data->posy = y + 0.5;
	}
	if (ft_strchrint(data->map[y], 'S') != -1)
	{
		data->posx = ft_strchrint(data->map[y], 'S') + 0.5;
		data->posy = y + 0.5;
	}
	if (ft_strchrint(data->map[y], 'E') != -1)
	{
		data->posx = ft_strchrint(data->map[y], 'E') + 0.5;
		data->posy = y + 0.5;
	}
}

void	init_ray(t_data *data, char Orient)
{
	data->ray.dir_x = 0;
	data->ray.dir_y = -1;
	data->ray.plane_x = 0.66;
	data->ray.plane_y = 0;
	if (Orient == 'S')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0;
	}
	else if (Orient == 'W')
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.66;
	}
	else if (Orient == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = 0.66;
	}
}
