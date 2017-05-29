/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:22:33 by niragne           #+#    #+#             */
/*   Updated: 2017/05/29 18:11:41 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char		***ft_getmap(int fd)
{
	char	*tmp;
	char	**ret;
	char	***slt;
	int		i;
	int		len;

	tmp = fd_to_str(fd);
	ret = ft_strsplit(tmp, '\n');
	if (!(slt = (char***)malloc(sizeof(char**) * ft_tablen(ret) + 1)))
		return (NULL);
	i = -1;
	while (ret[++i])
		slt[i] = ft_strsplit(ret[i], ' ');
	slt[i] = NULL;
	free_double(ret, ft_tablen(ret) + 1);
	free(tmp);
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
	if (!(dims = malloc(sizeof(int) * 4)))
		return (NULL);
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

t_point		**convert_map(char ***map, t_info info)
{
	int		i;
	int		j;
	t_point	**ret;

	i = 0;
	j = 0;
	if (!(ret = malloc(sizeof(t_point*) * info.mapy)))
		return (NULL);
	while (i < info.mapy)
	{
		if (!(ret[i] = malloc(sizeof(t_point) * info.mapx)))
			return (NULL);
		while (j < info.mapx)
		{
			ret[i][j] = ft_newpoint(((j
			* info.sq_size + info.sq_size / 2) + (((i - 1) * info.sq_size) / 2))
			- j * info.sq_size / 2 + info.firstx, ((((i * info.sq_size) / 2))
			- j * info.sq_size / 2 + info.firsty * 1.3) / 2,
			ft_atoi(map[i][j]));
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

int			ft_checkmap(char ***map)
{
	int i;
	int max;

	max = ft_tablen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_tablen(map[i]) != max)
			return (-1);
		i++;
	}
	return (1);
}
