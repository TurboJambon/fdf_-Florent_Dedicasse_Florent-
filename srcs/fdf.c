/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:00:52 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/31 13:45:39 by dchirol          ###   ########.fr       */
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
	if (!(ret = malloc(sizeof(t_point*) * info.mapy)))
		return (NULL);
	while (i < info.mapy)
	{
		if (!(ret[i] = malloc(sizeof(t_point) * info.mapx)))
			return (NULL);
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
	t_point	**tmp;

	i = -1;
	if (!(ret = malloc(sizeof(t_point*) * info.mapy)))
		return (NULL);
	while (++i < info.mapy)
	{
		j = 0;
		if (!(ret[i] = malloc(sizeof(t_point) * info.mapx)))
			return (NULL);
		while (j < info.mapx)
		{
			ret[i][j] = ft_newpoint(((j * SQ_SIZE + SQ_SIZE / ANGLE)
			+ (((i - 1) * SQ_SIZE) / ANGLE)) - j * SQ_SIZE / ANGLE + FIRSTX,
			((((i * SQ_SIZE) / ANGLE)) - j * SQ_SIZE /
			ANGLE + FIRSTY * 1.3) / 2, map[i][j].z);
			j++;
		}
	}
	tmp = apply_z(ret, info);
	free_points(ret, info.mapy);
	return (tmp);
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
				(map[i][j].x + SQ_SIZE > 0 && map[i][j].x - SQ_SIZE <
				info.winx) && map[i][j].y +
				SQ_SIZE > 0 && map[i][j].y - SQ_SIZE < info.winy)
				ft_trace(map[i][j], map[i][j + 1], e);
			if (i < info.mapy - 1 &&
				(map[i][j].x + SQ_SIZE > 0 && map[i][j].x - SQ_SIZE <
				info.winx) && map[i][j].y +
				SQ_SIZE > 0 && map[i][j].y - SQ_SIZE < info.winy)
				ft_trace(map[i][j], map[i + 1][j], e);
			j++;
		}
		j = 0;
		i++;
	}
}

int		key_hook(int keycode, t_env *e)
{
	t_point	**tmp;

	if (keycode == 53)
		exit(0);
	if (change_info(&e->info, keycode))
	{
		tmp = recalc(e->map.map, e->info);
		mlx_clear_window(e->mlx, e->win);
		ft_wireframe(tmp, e, e->info);
		free_points(tmp, e->info.mapy);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	***map;
	t_env	e;
	t_point	**tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1 || ac != 2)
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
	free_map(map, e.info.mapy, e.info.mapx);
	apply_z(e.map.map, e.info);
	tmp = apply_z(e.map.map, e.info);
	ft_wireframe(tmp, &e, e.info);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
