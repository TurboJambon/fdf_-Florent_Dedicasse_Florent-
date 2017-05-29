/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 05:04:16 by niragne           #+#    #+#             */
/*   Updated: 2017/05/29 18:02:59 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace(t_point a, t_point b, t_env *e)
{
	int			color;
	t_trace		seg;
	float		i;

	color = WHITE;
	seg.dx = b.x - a.x;
	seg.dy = b.y - a.y;
	seg.l = fabsf(seg.dx) > fabsf(seg.dy) ? fabsf(seg.dx) : fabsf(seg.dy);
	seg.dxl = seg.dx / seg.l;
	seg.dyl = seg.dy / seg.l;
	i = 0;
	while (i < seg.l)
	{
		mlx_pixel_put(e->image, e->win, a.x + seg.dxl *
		i, a.y + seg.dyl * i, color);
		i++;
	}
}
