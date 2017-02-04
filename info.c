/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:03:01 by niragne           #+#    #+#             */
/*   Updated: 2017/02/04 16:59:05 by niragne          ###   ########.fr       */
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
	ret.firstx = 0;
	ret.firsty = ret.winy;
	ret.scale = ret.sq_size / 3;
	ret.scalebase = ret.scale;
	return (ret);
}

int		change_info(t_info *info, int keycode)
{
	if (keycode == KP_PLUS)
	{
		info->scale += 2;
		return (1);
	}
	if (keycode == KP_MINUS)
	{
		info->scale -= 2;
		return (1);
	}
	if (keycode == PGUP)
		return (info->sq_size += 1);
	if (keycode == PGDOWN)
		return (info->sq_size -= 1);
	if (keycode == RIGHTARROW)
		return (info->firstx -= 10);
	if (keycode == LEFTARROW)
		return (info->firstx += 10);
	if (keycode == UPARROW)
		return (info->firsty += 10);
	if (keycode == DOWNARROW)
		return (info->firsty -= 10);
	return (0);
}
