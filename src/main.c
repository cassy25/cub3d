/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:00 by roroca            #+#    #+#             */
/*   Updated: 2024/01/11 14:51:41 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data *data)
{
	data->c = -1;
	data->f = -1;
	data->no.mlx_img = NULL;
	data->so.mlx_img = NULL;
	data->we.mlx_img = NULL;
	data->ea.mlx_img = NULL;
	data->map = NULL;
	data->sizemapx = 0;
	data->sizemapy = 0;
	data->move_speed = 0.2;
	data->rot_speed = 0.2;
	data->mlx = mlx_init();
}

void	ft_destroy_image(t_data *data)
{
	if (data->no.mlx_img)
	{
		mlx_destroy_image(data->mlx, data->no.mlx_img);
		data->no.mlx_img = NULL;
	}
	if (data->so.mlx_img)
	{
		mlx_destroy_image(data->mlx, data->so.mlx_img);
		data->so.mlx_img = NULL;
	}
	if (data->we.mlx_img)
	{
		mlx_destroy_image(data->mlx, data->we.mlx_img);
		data->we.mlx_img = NULL;
	}
	if (data->ea.mlx_img)
	{
		mlx_destroy_image(data->mlx, data->ea.mlx_img);
		data->ea.mlx_img = NULL;
	}
}

int	ft_destroy_data(t_data *data, int flag)
{
	ft_destroy_image(data);
	if (flag > 0)
	{
		mlx_destroy_window(data->mlx, data->wdw);
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	}
	mlx_destroy_display(data->mlx);
	if (data->map)
		ft_free_tab(data->map);
	free(data->mlx);
	exit (0);
	return (0);
}

void	ft_handling_map(char *file)
{
	t_data	data;

	ft_init_data(&data);
	if (ft_verif_content(file) || ft_verif_params(file, &data))
		ft_destroy_data(&data, 0);
	setup_map(&data, file);
	save_map(&data, file);
	if (check_all(&data) == 1)
		ft_destroy_data(&data, 0);
	player_pos(&data);
	set_floor_ceiling(&data);
	data.wdw = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_loop_hook(data.mlx, start_raycasting, &data);
	mlx_hook(data.wdw, 17, 1, ft_destroy_data, &data);
	mlx_hook(data.wdw, 2, 1, move_player, &data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Error : Wrong number of arguments\n"));
	if (ft_verif_file(av[1]))
		return (printf("Error : Incorrect file\n"));
	ft_handling_map(av[1]);
	return (0);
}
