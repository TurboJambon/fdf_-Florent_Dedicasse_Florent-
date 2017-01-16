/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:22:33 by niragne           #+#    #+#             */
/*   Updated: 2017/01/16 05:33:13 by niragne          ###   ########.fr       */
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
	return (slt);
}

t_point		**convert_map(char	***map, int x, int y, int inc)
{
	int 	i;
	int 	j;
	t_point	**ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(t_point**) * 1);
	while (map[i])
	{
		//ret[i] = malloc(1);
		while (map[i][j])
		{
			//printf("%s ", map[i][j]);
			//ret[i][j] = ft_newpoint(x + inc * j, y + inc * i, ft_atoi(map[i][j]));
			//printf("%d, %d, x: %d, y:%d, z: %d\n", i, j, ret[i][j].x, ret[i][j].y, ret[i][j].z);

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
