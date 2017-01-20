/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:22:33 by niragne           #+#    #+#             */
/*   Updated: 2017/01/20 16:30:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	***ft_getmap(int fd)
{
	char	*tmp;
	char	**ret;
	char	***slt;
	int		i;
	int		len;

	tmp = fd_to_str(fd);
	ret = ft_strsplit(tmp, '\n');
	slt = (char***)malloc(sizeof(char**) * ft_tablen(ret) + 1);
	i = 0;
	while (ret[i])
	{
		slt[i] = ft_strsplit(ret[i], ' ');
		i++;
	}
	slt[i] = NULL;
	return (slt);
}

int			ft_doubletablen(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			*get_map_dims(char ***map)
{
	int		*dims;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dims = malloc(sizeof(int) * 4);
	dims[0] = ft_tablen(map[0]);
	dims[1] = ft_doubletablen(map);
	dims[2] = 0;
	dims[3] = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (ft_atoi(map[i][j]) > dims[2])
				dims[2] = ft_atoi(map[i][j]);
			else if (ft_atoi(map[i][j]) < dims[3])
				dims[3] = ft_atoi(map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (dims);
}


t_point		**convert_map(char	***map, t_info info)
{
	int 	i;
	int 	j;
	t_point	**ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(t_point*) * info.mapy);
	while (i < info.mapy)
	{
		ret[i] = malloc(sizeof(t_point) * info.mapx);
		while (j < info.mapx)
		{
			//printf("bananananananananana %s\n", map[i][j]);
			ret[i][j] = ft_newpoint(
			((j * info.sq_size + info.sq_size / 2) + (((i - 1) * info.sq_size) / 2)) -
			j * info.sq_size / 2 + info.firstx,
			((((i * info.sq_size) / 2)) - j * info.sq_size / 2 + info.firsty * 1.3) / 2,
			ft_atoi(map[i][j]));
			//printf("i: %d, j: %d, x: %d, y:%d, z: %d\n", i, j, ret[i][j].x, ret[i][j].y, ret[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}


