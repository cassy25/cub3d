/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:18:41 by roroca            #+#    #+#             */
/*   Updated: 2023/12/15 18:11:10 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUBD

# include <stdio.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"


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
}		t_data;

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

/* utils.c */
int	ft_strncmp(char *s1, char *s2, size_t n);
void	ft_free_tab(char **tab);
int	ft_is_map(char *s);
int	ft_strlen(char *s);
int	ft_atoi(char *nptr);
/* error.c */
int	ft_verif_file(char *file);
/* main.c */
void	ft_handling_map(char *file);
void	ft_destroy_image(t_data *data);
void	ft_destroy_data(t_data *data);
void	ft_init_data(t_data *data);

#endif
