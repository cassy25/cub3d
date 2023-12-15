/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:07:40 by roroca            #+#    #+#             */
/*   Updated: 2023/12/15 17:00:23 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_receive_color(char *s, int res)
{
	int	i;
	int	j;
	long long	color;

	i = 1;
	j = 0;
	while (s[i] == 32)
		i++;
	s += i;
	if (ft_color(s) || res != 0)
		return (1);
	while (j < 3)
	{
		color = ft_atoi(s);
		if (color > 255 || color < 0)
			return (1);
		res = res * 256 + color;
		j++;
	}
	return (0);
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
