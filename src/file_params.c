/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:28:17 by roroca            #+#    #+#             */
/*   Updated: 2024/01/11 16:41:31 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//VERIF PLAYER OOB
int	ft_verif_content(char *file)
{
	int		fd;
	int		flag;
	int		flag2;
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
	int		fd;
	int		flag;
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
	close(fd);
	if (flag == 1)
		return (1);
	return (0);
}

int	ft_file_params(char *s, t_data *data)
{
	int		flag;
	void	*res;

	flag = -1;
	res = NULL;
	while (*s == 32)
		s++;
	if (ft_strncmp(s, "NO ", 3) == 0 || ft_strncmp(s, "SO ", 3) == 0
		|| ft_strncmp(s, "WE ", 3) == 0 || ft_strncmp(s, "EA ", 3) == 0)
		res = ft_handle_texture(s, data);
	else if (ft_strncmp(s, "F ", 2) == 0 || ft_strncmp(s, "C ", 2) == 0)
		flag = ft_handle_color(s, data);
	else
		return (printf("Error : Invalid parameter in file\n"));
	if (flag == -1 && res == NULL)
		return (1);
	return (0);
}

void	*ft_handle_texture(char *s, t_data *data)
{
	t_img	res;
	char	*tex;

	tex = s;
	tex += 2;
	while (*tex == 32)
		tex++;
	tex[ft_strlen(tex) - 1] = 0;
	res.mlx_img = mlx_xpm_file_to_image(data->mlx, tex, &res.x, &res.y);
	if (res.mlx_img == NULL)
		return (printf("Error : Texture Invalid\n"), NULL);
	if (ft_strncmp(s, "NO ", 3) == 0 && data->no.mlx_img == NULL)
		data->no = res;
	else if (ft_strncmp(s, "SO ", 3) == 0 && data->so.mlx_img == NULL)
		data->so = res;
	else if (ft_strncmp(s, "WE ", 3) == 0 && data->we.mlx_img == NULL)
		data->we = res;
	else if (ft_strncmp(s, "EA ", 3) == 0 && data->ea.mlx_img == NULL)
		data->ea = res;
	else
	{
		mlx_destroy_image(data->mlx, res.mlx_img);
		return (printf("Error : Parameter in double\n"), NULL);
	}
	return (res.mlx_img);
}
