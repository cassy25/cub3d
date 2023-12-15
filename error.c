/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roroca <roroca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:18:24 by roroca            #+#    #+#             */
/*   Updated: 2023/12/15 14:20:26 by roroca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_file(char *file)
{
	int	i;
	int	j;
	char	*str;

	if (!file)
		return (1);
	i = 0;
	j = (ft_strlen(file) - 1);
	str = "buc.";
	while (i <= 3)
	{
		if (str[i++] != file[j--])
			return (1);
	}
	if (j == -1)
		return (1);
	if (file[j] == '/')
		return (1);
	i = open(file, O_RDONLY);
	if (i == -1)
		return (1);
	j = read(i, 0, 0);
	if (j == -1)
		return (1);
	return (0);
}
