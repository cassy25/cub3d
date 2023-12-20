/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:00 by roroca            #+#    #+#             */
/*   Updated: 2023/12/19 18:57:12 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data *data)
{
	data->C = 0;
	data->F = 0;
	data->NO = NULL;
	data->SO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->map = NULL;
	data->sizemapx = 0;
	data->sizemapy = 0;
	data->mlx = mlx_init();
	data->wdw = mlx_new_window(data->mlx, 1920, 1080, "Cub3D");
}

void	ft_destroy_image(t_data *data)
{
	if (data->NO)
	{
		mlx_destroy_image(data->mlx, data->NO);
		data->NO = NULL;
	}
	if (data->SO)
	{
		mlx_destroy_image(data->mlx, data->SO);
		data->SO = NULL;
	}
	if (data->WE)
	{
		mlx_destroy_image(data->mlx, data->WE);
		data->WE = NULL;
	}
	if (data->EA)
	{
		mlx_destroy_image(data->mlx, data->EA);
		data->EA = NULL;
	}
}

void	ft_destroy_data(t_data *data)
{
	ft_destroy_image(data);
	if (data->map)
		ft_free_tab(data->map);
	mlx_destroy_window(data->mlx, data->wdw);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit (0);
}

void	ft_handling_map(char *file)
{
	t_data *data;
	
	//(void)file;
	data = malloc(sizeof(t_data));
	ft_init_data(data);
	if (ft_verif_content(file))
	{
		ft_destroy_data(data);
		printf("1");
	}/*
	if (ft_verif_params(file, data))
	{
		ft_destroy_data(data);
		printf("2");
	}*/
	setup_map(data, file);
	save_map(data, file);
	printf("gg");
	if (check_all(data) == 1)
		return ;
	//ft_destroy_data(data);
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
