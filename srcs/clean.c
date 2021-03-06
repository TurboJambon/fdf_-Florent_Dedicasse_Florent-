/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:23:05 by niragne           #+#    #+#             */
/*   Updated: 2017/06/17 14:47:23 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points(t_point **arr, int mapy)
{
	int i;

	i = 0;
	while (i < mapy)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(char ***map, int mapy, int mapx)
{
	int i;
	int y;

	i = 0;
	while (i < mapy)
	{
		y = 0;
		{
			while (y < mapx)
			{
				free(map[i][y]);
				y++;
			}
		}
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_double(char **tab, int mapy)
{
	int i;

	i = 0;
	while (i < mapy)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_dims(int *dims, char ***map)
{
	dims[0] = ft_tablen(map[0]);
	dims[1] = ft_doubletablen(map);
	dims[2] = 0;
	dims[3] = 0;
}
