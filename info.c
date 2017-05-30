/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:03:01 by niragne           #+#    #+#             */
/*   Updated: 2017/05/30 18:04:13 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_info	ft_get_info(char ***map)
{
	int		*dims;
	t_info	ret;

	dims = get_map_dims(map);
	ret.mapx = dims[0];
	ret.mapy = dims[1];
	ret.winx = WIN_X;
	ret.winy = WIN_Y;
	ret.sq_size = (ret.mapx > ret.mapy) ?
	ret.winx / ret.mapx : ret.winy / ret.mapy;
	if (ret.winy > 1440)
		ret.winy = 1440;
	ret.highest = dims[2];
	ret.lowest = dims[3];
	ret.firstx = ret.winx / 8;
	ret.firsty = ret.winy;
	ret.scale = ret.sq_size / 3;
	ret.scalebase = ret.scale;
	ret.angle = 2;
	free(dims);
	return (ret);
}

int		change_info(t_info *info, int keycode)
{
	if (keycode == KP_PLUS)
		return ((info->scale += 2) || 1);
	if (keycode == KP_MINUS)
		return ((info->scale -= 2) || 1);
	if (keycode == PGUP)
		return ((info->sq_size += 1) || 1);
	if (keycode == PGDOWN)
		return ((info->sq_size -= 1) || 1);
	if (keycode == RIGHTARROW)
		return (info->firstx -= 10);
	if (keycode == LEFTARROW)
		return (info->firstx += 10);
	if (keycode == UPARROW)
		return (info->firsty += 10);
	if (keycode == DOWNARROW)
		return (info->firsty -= 10);
	if (keycode == A)
		if (info->angle > 1.6)
			return (info->angle -= 0.2);
	if (keycode == D)
		if (info->angle < 10)
			return (info->angle += 0.2);
	if (keycode == S)
		return (info->angle = 2);
	return (0);
}
