/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:07:42 by roroca            #+#    #+#             */
/*   Updated: 2023/12/19 18:57:11 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void save_map2(t_data *data)
{
    int i;
    int j;
    int len;

    i = 0;
    len = 0;
    while (i < data->sizemapy)
    {
        len = ft_strlen(data->map[i]);
        j = 0;
        while (j < len)
        {
            if (data->map[i][j] == '\n')
                data->map[i][j] = '\0';
            j++;
        }
        i++;
    }
}

void max_len(t_data *data)
{
    int max_len;
    int i;
    int len;
    
    max_len = 0;
    i = 0;
    len = 0;
    while (i < data->sizemapy - 1)
    {
        
        len = ft_strlen(data->map[i]);
        if (len > max_len)
            max_len = len;
        i++;    
    }
    complete_line(data, max_len);
}

void complete_line(t_data *data, int max_len)
{
    int current_len;
    int j;
    int i;
    
    current_len = 0;
    j = 0;
    i = 0;
    while (i < data->sizemapy - 1)
    {
        current_len = ft_strlen(data->map[i]);
        if (current_len < max_len)
        {
            data->map[i] = realloc(data->map[i], max_len + 1);
            j = current_len;
            while (j < max_len)
            {
                data->map[i][j] = '1';
                j++;
            }
            data->map[i][max_len] = '\0';
        }
        i++;
    }
}
