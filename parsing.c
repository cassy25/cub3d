/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:53 by cgeoffra          #+#    #+#             */
/*   Updated: 2023/12/19 18:57:09 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void setup_map(t_data *data, char *str)
{
    int fd;
    char *s;

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

void save_map(t_data *data, char *str)
{
    int fd;
    int i;
    char *s;

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
        data->map[i] = s; 
        s = get_next_line(fd);
        i++;
    }
    close(fd);
    fd = open(str, O_RDONLY);
    //save_map2(data);
    //max_len(data);
    close(fd);
}

int check_map_wall(t_data *data)
{
    int y;
    int x;
    
    y = 0;
	if (ft_strchr(data->map[0], 0) != -1 || ft_strchr(data->map[data->sizemapy], 0) != -1)
		return (1);
	while (y < data->sizemapy)
    {
		if (data->map[y][0] == 0 || data->map[y][ft_strlen(data->map[y]) - 1] == 0)
			return (1);
		if (y > 0 && y < data->sizemapy)
		{
			
		}
		y++;
	}
	
	/*
    while (y < data->sizemapy)
    {
        if (y == 0 || y == data->sizemapy - 1)
        {
            x = 0;
            while (x < data->sizemapx - 1)
            {
                if (data->map[y][x] != '1')
                    return (1);
                x++;
            }
        }
        else
        {
            if (data->map[y][0] != '1'|| data->map[y][data->sizemapx - 1] != '1')
                return (1);
        }
        y++;
    }*/
    return (0);
}
int check_map(t_data *data)
{
    int x;
    int y;
    int flag;

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

int check_all(t_data *data)
{
    if (check_map(data) != 1)
    {
        printf("Map is not valid\n");
        return (1);
    }
    if (check_map_wall(data) == 1)
    {
        printf("Map is not valid : wall");
        return (1);
    }
    return (0);
}
