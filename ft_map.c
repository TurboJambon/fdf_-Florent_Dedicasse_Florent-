/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:22:33 by niragne           #+#    #+#             */
/*   Updated: 2017/01/18 16:13:09 by niragne          ###   ########.fr       */
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

	i = 1;
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

	dims = malloc(sizeof(int) * 2);
	dims[0] = ft_tablen(map[0]);
	dims[1] = ft_doubletablen(map);
	return (dims);
}


t_point		**convert_map(char	***map, int x, int y, int inc, int mapx, int mapy)
{
	int 	i;
	int 	j;
	t_point	**ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(t_point*) * mapy);
	while (i < mapy)
	{
		ret[i] = malloc(sizeof(t_point) * mapx);
		while (j < mapx)
		{
			//printf("bananananananananana %s\n", map[i][j]);
			ret[i][j] = ft_newpoint(x + inc * j + i * inc / 6 , y + inc / 6 * i, ft_atoi(map[i][j]));
			//printf("i: %d, j: %d, x: %d, y:%d, z: %d\n", i, j, ret[i][j].x, ret[i][j].y, ret[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

int		ft_checkmap(char **str)
{
	int i;
	int len;

	i = 1;
	len = ft_strlen(str[0]);
	while (str[i])
	{
		if (ft_strlen(str[i]) != len)
			return (0);
		i++;
	}
	return (i);
}
