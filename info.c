/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:03:01 by niragne           #+#    #+#             */
/*   Updated: 2017/01/20 18:25:03 by niragne          ###   ########.fr       */
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
	ret.sq_size = (dims[0] > dims[1]) ? 1000 / dims[0] : 1000 / dims[1];
	ret.winx = (ret.sq_size * ret.mapx > 2560) ? 2560 : ret.sq_size * ret.mapx;
	ret.winy = 300 + ret.sq_size / 3 * ret.mapy + ret.sq_size * dims[2];
	if (ret.winy > 1440)
		ret.winy = 1440;
	ret.highest = dims[2];
	ret.lowest = dims[3];
	ret.firstx = 0;
	ret.firsty = ret.winy;
	return (ret);
}
