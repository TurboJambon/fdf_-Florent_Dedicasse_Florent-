/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:54:07 by niragne           #+#    #+#             */
/*   Updated: 2017/06/17 14:47:36 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_clear_image(t_image *img, t_uint color)
{
	int		i;
	int		size;

	size = img->sizeline * img->line;
	i = 0;
	while (i < size)
	{
		img->data[i] = color;
		i++;
	}
}

t_image		ft_new_image(void *mlx, int x, int y)
{
	t_image		ret;

	ret.image = mlx_new_image(mlx, x, y);
	ret.data = (t_uint *)mlx_get_data_addr(ret.image, &ret.bpp,
											&ret.sizeline, &ret.endian);
	ret.sizeline >>= 2;
	ret.line = y;
	return (ret);
}

void		ft_putpixel(t_image *img, int x, int y, t_uint color)
{
	if (x >= 0 && y >= 0 && x < img->sizeline && y < img->line)
		img->data[x + y * img->sizeline] = color;
}
