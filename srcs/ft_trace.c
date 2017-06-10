/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:45:45 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/10 13:37:47 by niragne          ###   ########.fr       */
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
		ft_putpixel(&e->image, a.x + seg.dxl *
		i, a.y + seg.dyl * i, color);
		i++;
	}
}
