/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:35 by niragne           #+#    #+#             */
/*   Updated: 2017/01/17 03:38:08 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

#define MAPX 19
#define MAPY 11

void	ft_trace(t_point a, t_point b, t_env *e) // Trace des segments
{
	int color = 0xFF02;
	float dx;
	float dy;
	float l;
	int i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	l = sqrt(pow(b.x + b.y, 2));
	i = 0;
	while (i < l)
	{
		if (b.z)
			color = 0xFFFF;
		mlx_pixel_put(e->mlx, e->win, 
		a.x + ((dx / l) * i), 		
		a.y + ((dy / l) * i), 		
		color);
		i++;
	}
}

void	apply_z(t_point ***map, int mapx, int mapy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mapy)
	{
		while (j < mapx)
		{
			map[0][i][j].x -= map[0][i][j].z * 5;
			map[0][i][j].y -= map[0][i][j].z * 10;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_wireframe(t_point **map, t_env *e, int mapx, int mapy)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mapy)
	{
		while (j < mapx)
		{
			if (j < mapx - 1)
				ft_trace(map[i][j], map[i][j + 1], e);
			if (i < mapy - 1)
				ft_trace(map[i][j], map[i + 1][j], e);
			j++;
		}
		j = 0;
		i++;
	}
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	int fd;
	char ***map;
	int i=0;
	int j=0;
	t_env e;
	int k=0;
	t_point		**salut;
	int *dims;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1500, 1000, "banane");
	fd = open(av[1], O_RDONLY);
	map = ft_getmap(fd);
	printf("JOHARNO\n");
	dims = get_map_dims(map);
	printf("SALUT LES GROS GARS%d, %d\n", dims[0], dims[1]);
	while (i < dims[1])
	{
		while (j < dims[0])
		{
			printf("%s ", map[i][j]);
			j++;
		}
		j = 0;
		printf(" \n");
		i++;	
	}
	printf("BA\n");
	salut = convert_map(map, 200, 250, 70, dims[0], dims[1]);
	printf("SAUCISSE\n");
	i = 0; j = 0;
	while (i < dims[1])
	{
		while (j < dims[0])
		{
			printf("%d;%d ", salut[i][j].x, salut[i][j].y);
			j++;
		}
		j = 0;
		i++;
		printf(" \n");
	}
	printf("sous la saucisse\n");
	apply_z(&salut, dims[0], dims[1]);
	ft_wireframe(salut, &e, dims[0], dims[1]);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}



















