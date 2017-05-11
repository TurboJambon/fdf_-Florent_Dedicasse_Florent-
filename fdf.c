/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:35 by niragne           #+#    #+#             */
/*   Updated: 2017/02/18 19:06:59 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

t_point	**apply_z(t_point **map, t_info info)
{
	int		i;
	int		j;
	t_point **ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(t_point*) * info.mapy);
	while (i < info.mapy)
	{
		ret[i] = malloc(sizeof(t_point) * info.mapx);
		while (j < info.mapx)
		{
			ret[i][j] = ft_newpoint(map[i][j].x,
			map[i][j].y - map[i][j].z * info.scale, 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (ret);
}

t_point	**recalc(t_point **map, t_info info)
{
	int		i;
	int		j;
	t_point **ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(t_point*) * info.mapy);
	while (i < info.mapy)
	{
		ret[i] = malloc(sizeof(t_point) * info.mapx);
		while (j < info.mapx)
		{
			ret[i][j] = ft_newpoint(((j
			* info.sq_size + info.sq_size / info.angle) + (((i - 1) *
			info.sq_size) / info.angle)) - j * info.sq_size / info.angle +
			info.firstx, ((((i * info.sq_size) / info.angle))
			- j * info.sq_size / info.angle + info.firsty * 1.3) / 2,
			map[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
	return (ret = apply_z(ret, info));
}

void	ft_wireframe(t_point **map, t_env *e, t_info info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info.mapy)
	{
		while (j < info.mapx)
		{
			if (j < info.mapx - 1 &&
				(map[i][j].x + info.sq_size > 0 && map[i][j].x - info.sq_size <
				info.winx) && map[i][j].y +
				info.sq_size > 0 && map[i][j].y - info.sq_size < info.winy)
				ft_trace(map[i][j], map[i][j + 1], e);
			if (i < info.mapy - 1 &&
				(map[i][j].x + info.sq_size > 0 && map[i][j].x - info.sq_size <
				info.winx) && map[i][j].y +
				info.sq_size > 0 && map[i][j].y - info.sq_size < info.winy)
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
	if (change_info(&e->info, keycode))
	{
		mlx_clear_window(e->mlx, e->win);
		ft_wireframe(recalc(e->map.map, e->info), e, e->info);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	***map;
	t_env	e;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_puterr(ERR_FILE));
	map = ft_getmap(fd);
	if (ft_checkmap(map) == -1)
		return (ft_puterr(ERR_MAP));
	e.info = ft_get_info(map);
	if (!(e.mlx = mlx_init()))
		return (ft_puterr(ERR_WINDOW));
	e.win = mlx_new_window(e.mlx, e.info.winx, e.info.winy, "fdf");
	e.image = mlx_new_image(e.mlx, e.info.winx, e.info.winy);
	mlx_put_image_to_window(e.mlx, e.win, e.image, 0, 0);
	e.map.map = convert_map(map, e.info);
	apply_z(e.map.map, e.info);
	ft_wireframe(apply_z(e.map.map, e.info), &e, e.info);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
