/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:29 by niragne           #+#    #+#             */
/*   Updated: 2017/01/20 18:36:45 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WHITE 0x00FFFFFF
# define BLUE 0xFF
# define GREEN 0xFF00
# define RED 0xFF0000
# include <mlx.h>
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct	s_env
{
	void *mlx;
	void *win;
	void *image;
}				t_env;

typedef struct	s_map
{
	t_point	**map;
	int		x;
	int		y;

}				t_map;

typedef struct	s_trace
{
	float	dx;
	float	dy;
	float	l;
	float	dxl;
	float	dyl;
}				t_trace;

typedef struct	s_info
{
	int		mapx;
	int		mapy;
	int		winx;
	int		winy;
	int		sq_size;
	int		firstx;
	int		firsty;
	int		highest;
	int		lowest;
}				t_info;

int				ft_checkmap(char ***map);
char			***ft_getmap(int fd);
t_point			**convert_map(char	***map, t_info info);
int				ft_doubletablen(char ***tab);
int				*get_map_dims(char ***map);
t_info			ft_get_info(char ***map);
int				ft_puterr(char *str);

#endif
