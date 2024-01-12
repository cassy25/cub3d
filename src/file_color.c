/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:07:40 by roroca            #+#    #+#             */
/*   Updated: 2024/01/08 14:51:42 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_receive_color(char *s)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (s[i] == 32)
		i++;
	s += i;
	if (ft_color(s))
		return (printf("Error : Invalid parameter color\n"), -1);
	res = ft_receive_color2(s);
	return (res);
}

int	ft_receive_color2(char *s)
{
	int				res;
	long long		color;
	int				j;

	j = 0;
	res = 0;
	while (j < 3)
	{
		if (*s == 0)
			return (printf("Error : Missing value color\n"), -1);
		color = ft_atoi(s);
		if (color > 255 || color < 0)
			return (printf("Error : Color out of bounds\n"), -1);
		res = res * 256 + color;
		while (*s && *s != ',')
			s++;
		if (*s == ',')
			s++;
		j++;
	}
	return (res);
}

int	ft_color(char *s)
{
	int	i;

	i = 0;
	s[ft_strlen(s) - 1] = 0;
	while (s[i])
	{
		if ((s[i] < 48 || s[i] > 57) && s[i] != ',')
			return (1);
		if (s[i] == ',' && s[i + 1] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	ft_handle_color(char *s, t_data *data)
{
	int	res;

	res = ft_receive_color(s);
	if (ft_strncmp(s, "F ", 2) == 0 && data->f == -1)
		data->f = res;
	else if (ft_strncmp(s, "C ", 2) == 0 && data->c == -1)
		data->c = res;
	else
		return (printf("Error : Parameter in double\n"), -1);
	return (res);
}
