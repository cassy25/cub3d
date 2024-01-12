/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:28:18 by cgeoffra          #+#    #+#             */
/*   Updated: 2024/01/11 18:15:19 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH		1920
# define HEIGHT		1080
# define KEY_W		119
# define KEY_S		115
# define KEY_D		100
# define KEY_A		97
# define KEY_RIGHT	65363
# define KEY_LEFT	65361

typedef struct s_drawtex
{
	double	wallx;
	double	step;
	double	texpos;
	int		texx;
	int		texy;
}		t_drawtex;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line;
	int					endian;
	int					x;
	int					y;
}		t_img;

typedef struct s_raycast
{
	double				camera_x;
	double				x; // Position camera
	double				y;
	double				dir_x; // Direction de la camera
	double				dir_y;
	double				old_dir_x;
	double				plane_x; // Plan du vecteur de la camera
	double				plane_y;
	double				old_plane_x;
	double				ray_dirx; // Direction du rayon
	double				ray_diry;
	double				side_disty; // longueur du rayon jusqu'a ce qu'il atteigne le mur
	double				side_distx;
	int					side;
	double				delta_distx; // distance entre les intersections du rayon
	double				delta_disty;
	int					mapx; // Position initiale du rayon
	int					mapy;
	int					stepx; //Indique un deplacement selon sa valeur
	int					stepy;
	int					collision;
	double				wall_dist;
	int					line_height;
	int					start_line;
	int					end_line;
}		t_raycast;

typedef struct s_data
{
	void			*mlx;
	void			*wdw;
	char			**map;
	t_img			no;
	t_img			so;
	t_img			ea;
	t_img			we;
	int				f;
	int				c;
	double			posy;
	double			posx;
	int				sizemapx;
	int				sizemapy;
	double			move_speed;
	double			rot_speed;
	t_img			img;
	t_raycast		ray;
}		t_data;

/* raycasting.c */
void		raycasting(t_data *data, int x);
void		raycasting2(t_data *data);
void		collision_wall(t_data *data);
void		dist_wall(t_data *data);
/* raycasting2.c */
int			start_raycasting(t_data *data);
void		draw_wall(t_data *data, int x);
t_drawtex	ft_tex_coordinates(t_data *data, t_img tex);
t_img		ft_wall_tex(t_data *data);
/* file_params.c */
int			ft_verif_content(char *file);
int			ft_verif_params(char *file, t_data *data);
int			ft_file_params(char *s, t_data *data);
void		*ft_handle_texture(char *s, t_data *data);
/* file_color.c */
int			ft_receive_color(char *s);
int			ft_receive_color2(char *s);
int			ft_color(char *s);
int			ft_handle_color(char *s, t_data *data);
/* file_map.c */
void		init_ray(t_data *data, char Orient);
void		complete_line(t_data *data, int l, char *s);
void		player_pos(t_data *data);
void		player_pos2(t_data *data, int y);
/* utils.c */
int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_free_tab(char **tab);
int			ft_is_map(char *s);
int			ft_strlen(char *s);
int			ft_atoi(char *nptr);
/* utils2.c */
int			ft_strchrint(char *s, char c);
/* error.c */
int			ft_verif_file(char *file);
/* parsing.c */
void		setup_map(t_data *data, char *str);
void		save_map(t_data *data, char *str);
int			check_map_wall(t_data *data, char c);
int			check_map(t_data *data);
int			check_all(t_data *data);
/* controls.c */
int			move_player(int keysym, t_data *data);
int			move_camera(int keysym, t_data *data);
/* controls2.c */
void		key_d(t_data *data);
void		key_s(t_data *data);
void		key_a(t_data *data);
void		key_w(t_data *data);
/* set_floor_ceiling.c */
void		set_floor_ceiling(t_data *data);
void		render_background(t_data *data);
void		img_pix_put(t_img img, int x, int y, int color);
int			img_pix_color(t_img img, int x, int y);
/* main.c */
void		ft_handling_map(char *file);
void		ft_destroy_image(t_data *data);
int			ft_destroy_data(t_data *data, int flag);
void		ft_init_data(t_data *data);
//void	print_map_test(char **s);

#endif
