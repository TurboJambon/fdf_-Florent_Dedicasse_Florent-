/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:35 by niragne           #+#    #+#             */
/*   Updated: 2017/01/20 18:38:42 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_trace(t_point a, t_point b, t_env *e)
{
	int		color;
	t_trace seg;
	int		i;

	color = WHITE;
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
		mlx_pixel_put(e->image, e->win, a.x + (seg.dxl * i), a.y +
			((seg.dyl) * i), color);
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
			map[0][i][j].y -= map[0][i][j].z * info.sq_size / 1.3;
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

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	***map;
	t_env	e;
	t_point	**salut;
	t_info	info;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_puterr("aaaa"));
	map = ft_getmap(fd);
	if (ft_checkmap(map) == -1)
		return (ft_puterr("tarete"));
	info = ft_get_info(map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, info.winx, info.winy, "banane");
	e.image = mlx_new_image(e.mlx, info.winx, info.winy);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	salut = convert_map(map, info);
	apply_z(&salut, info);
	ft_wireframe(salut, &e, info.mapx, info.mapy);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
