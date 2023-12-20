/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:18:41 by roroca            #+#    #+#             */
/*   Updated: 2023/12/19 18:57:10 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUBD

# include <stdio.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 24
# define HEIGHT 24
# define KEY_A		119
# define KEY_S		115
# define KEY_D		100
# define KEY_W		97

typedef struct s_data
{
	void	*mlx;
	void	*wdw;
	char	**map;
	void	*NO;
	void	*SO;
	void	*EA;
	void	*WE;
	int		F;
	int		C;
	int posY;
	int posX;
	int sizemapx;
	int sizemapy;
	//t_raycast ray;
}		t_data;

typedef struct s_raycast
{
	double camera_x;

	double x; // Position camera
	double y;
	double dir_X; // Direction de la camera
	double dir_Y;
	double plane_X; // Plan du vecteur de la camera
	double plane_Y;
	double ray_dirX; // Direction du rayon
	double ray_dirY;
	double side_distY; // longueur du rayon jusqu'a ce qu'il atteigne le mur
	double side_distX;
	double delta_distX; // distance entre les intersections du rayon
	double delta_distY;
	int mapX; // Position initiale du rayon
	int mapY;
	int stepX; //Indique un deplacement selon sa valeur
	int stepY;
	int hit;
	
}		t_raycast;

/* file_params.c */
int	ft_verif_content(char *file);
int	ft_verif_params(char *file, t_data *data);
int	ft_file_params(char *s, t_data *data);
int	ft_receive_text(char *s, void *res, t_data *t_data);
void ft_init_str(char *s, t_data *data);
/* file_color.c */
int	ft_receive_color(char *s, int res);
int	ft_color(char *s);
/* file_map.c */
void save_map2(t_data *data);
void max_len(t_data *data);
void complete_line(t_data *data, int max_len);
/* utils.c */
int	ft_strncmp(char *s1, char *s2, size_t n);
void	ft_free_tab(char **tab);
int	ft_is_map(char *s);
int	ft_strlen(char *s);
int	ft_atoi(char *nptr);
/* utils2.c */
int ft_strchr(char *s, char c)
/* error.c */
int	ft_verif_file(char *file);
/* parsing.c */
void setup_map(t_data *data, char *str);
void save_map(t_data *data, char *str);
int check_map_wall(t_data *data);
int check_map(t_data *data);
/* controls.c */
int	move_player(int keysym, t_data *data);
int	move_player_y(t_data *game, int i);
int	move_player_x(t_data *game, int i);
int check_all(t_data *data);
/* main.c */
void	ft_handling_map(char *file);
void	ft_destroy_image(t_data *data);
void	ft_destroy_data(t_data *data);
void	ft_init_data(t_data *data);

#endif
