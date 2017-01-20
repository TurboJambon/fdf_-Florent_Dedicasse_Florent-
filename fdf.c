/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:35 by niragne           #+#    #+#             */
/*   Updated: 2017/01/20 16:34:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_trace(t_point a, t_point b, t_env *e) // Trace des segments
{
	int color = WHITE;
	t_trace seg;
	int i;

	seg.dx = b.x - a.x;
	seg.dy = b.y - a.y;
	seg.l = b.x + b.y;
	seg.dxl = seg.dx / seg.l;
	seg.dyl = seg.dy / seg.l;
	i = 0;
	while (i < seg.l)
	{
		if (b.z || a.z)
			color = WHITE;
		mlx_pixel_put(e->image, e->win, a.x + (seg.dxl * i), a.y + ((seg.dyl) * i), color);
		i++;
	}
}

void	apply_z(t_point ***map, t_info info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info.mapy)
	{
		while (j < info.mapx)
		{
			//map[0][i][j].x += map[0][i][j].z * 2;
			map[0][i][j].y -= map[0][i][j].z * info.sq_size / 1.5;
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
	if (keycode)
		printf("%i\n", keycode);
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
	t_info info;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_puterr("aaaa"));
	map = ft_getmap(fd);
	info = ft_get_info(map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, info.winx, info.winy, "banane");
	e.image = mlx_new_image(e.mlx, info.winx, info.winy);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	printf("JOHARNO\n");
	dims = get_map_dims(map);
	printf("SALUT LES GROS GARS %d, %d\n", dims[0], dims[1]);
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
	salut = convert_map(map, info);
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
	printf("winx %d winy %d sq size %d mapx %d mapy %d firstx %d firsty %d highest %d lowest %d\n", info.winx, info.winy, info.sq_size, info.mapx, info.mapy, info.firstx, info.firsty, info.highest, info.lowest);
	apply_z(&salut, info);
	ft_wireframe(salut, &e, dims[0], dims[1]);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
