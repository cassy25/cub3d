/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgeoffra <cgeoffra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:18:22 by roroca            #+#    #+#             */
/*   Updated: 2024/01/08 14:15:57 by cgeoffra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_is_map(char *s)
{
	int	i;
	int	flag;
	int	limit;

	i = 0;
	flag = 0;
	limit = ft_strlen(s) - 1;
	if (s[0] == '\n')
		return (0);
	while (i < limit)
	{
		if (s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W'
			&& s[i] != ' ' && s[i] != '1' && s[i] != '0')
			return (0);
		else if (s[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *nptr)
{
	int					i;
	int					neg;
	long long			nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = (nbr * 10) + nptr[i] - 48;
		i++;
	}
	return (nbr * neg);
}
