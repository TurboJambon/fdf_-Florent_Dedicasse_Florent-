/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:21:22 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:50:55 by dchirol          ###   ########.fr       */
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
