/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:28:17 by roroca            #+#    #+#             */
/*   Updated: 2023/12/18 16:16:00 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_content(char *file)
{
	int	fd;
	int	flag;
	int	flag2;
	char	*s;

	flag = 0;
	flag2 = 0;
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strncmp(s, "\n", 2) != 0)
			flag++;
		if (ft_is_map(s))
			flag2++;
		free(s);
		s = get_next_line(fd);
	}
	if (flag - flag2 != 6)
	{
		printf("Error : Invalid number of parameters in file\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_verif_params(char *file, t_data *data)
{
	int	fd;
	int	flag;
	char	*s;

	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	flag = 0;
	while (s)
	{
		if (ft_strncmp(s, "\n", 2) && ft_is_map(s) == 0 && flag == 0)
			if (ft_file_params(s, data))
				flag = 1;
		free(s);
		s = get_next_line(fd);
	}
	if (flag == 1)
		return (1);
	return (0);
}

int	ft_file_params(char *s, t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	while (s[i] == 32)
		i++;
	s += i;
	if (ft_strncmp(s, "NO ", 3) == 0)
		flag = ft_receive_text(s, data->NO, data);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		flag = ft_receive_text(s, data->SO, data);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		flag = ft_receive_text(s, data->WE, data);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		flag = ft_receive_text(s, data->EA, data);
	else if (ft_strncmp(s, "F ", 2) == 0)
		flag = ft_receive_color(s, data->F);
	else if (ft_strncmp(s, "C ", 2) == 0)
		flag = ft_receive_color(s, data->C);
	else
		return (printf("Error : Invalid parameter in file\n"));
	return (flag);
}

int	ft_receive_text(char *s, void *res, t_data *data)
{
	int	i;
	int	pixels;

	pixels = 64;
	i = 2;
	while (s[i] == 32)
		i++;
	s += i;
	s[ft_strlen(s) - 1] = 0;
	if (res != NULL)
		return (printf("Error : Parameter in double\n"));
	if (s[0] == '\0')
		return (printf("Error : No texture in parameter\n"));
	res = mlx_xpm_file_to_image(data->mlx, s, &pixels, &pixels);
	if (res == NULL)
		return (printf("Error : Texture Invalid\n"));
	ft_init_str(s, data);
	return (0);
}

void ft_init_str(char *s, t_data *data)
{
	if (ft_strncmp(s, "NO ", 3) == 0)
		data->NO = ft_strdup(s);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		data->SO = ft_strdup(s);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		data->WE = ft_strdup(s);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		data->EA = ft_strdup(s);
}