/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:53 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/09 14:44:50 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_map(t_data *data, char *str)
{
	int		fd;
	char	*s;

	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	while (ft_is_map(s) == 0)
	{
		free(s);
		s = get_next_line(fd);
	}
	while (s)
	{
		if (data->sizemapx < ft_strlen(s) - 1)
			data->sizemapx = ft_strlen(s) - 1;
		data->sizemapy++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

void	save_map(t_data *data, char *str)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	while (ft_is_map(s) == 0)
	{
		free(s);
		s = get_next_line(fd);
	}
	data->map = malloc(sizeof(char **) * (data->sizemapy + 1));
	data->map[data->sizemapy] = 0;
	while (i < data->sizemapy)
	{
		complete_line(data, i, s);
		s = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	check_map_wall(t_data *data, char c)
{
	int	y;
	int	x;

	y = 1;
	if (ft_strchrint(data->map[0], c) != -1
		|| ft_strchrint(data->map[data->sizemapy - 1], c) != -1)
		return (1);
	while (y < data->sizemapy)
	{
		x = 1;
		if (data->map[y][0] == c ||
			data->map[y][ft_strlen(data->map[y]) - 1] == c)
			return (1);
		while (x < data->sizemapx)
		{
			if (data->map[y][x] == c && (data->map[y + 1][x] == ' '
				|| data->map[y - 1][x] == ' ' || data->map[y][x + 1] == ' '
					|| data->map[y][x - 1] == ' '))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	y = 0;
	while (y < data->sizemapy - 1)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				flag += 1;
			if (data->map[y][x] == 'N')
				flag += 1;
			if (data->map[y][x] == 'S')
				flag += 1;
			if (data->map[y][x] == 'W')
				flag += 1;
			x++;
		}
		y++;
	}
	return (flag);
}

int	check_all(t_data *data)
{
	if (check_map(data) != 1)
	{
		printf("Error : Map is not valid\n");
		return (1);
	}
	if (check_map_wall(data, '0') == 1)
	{
		printf("Error : Map is not surrounded by walls\n");
		return (1);
	}
	return (0);
}
