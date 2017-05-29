/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 15:09:19 by niragne           #+#    #+#             */
/*   Updated: 2017/05/29 18:19:29 by dchirol          ###   ########.fr       */
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