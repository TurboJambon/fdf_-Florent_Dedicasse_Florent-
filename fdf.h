/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:29 by niragne           #+#    #+#             */
/*   Updated: 2017/02/04 16:22:59 by niragne          ###   ########.fr       */
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
# define ERR_WINDOW "window error"
# define ERR_FILE "file error"
# define ERR_MAP "map error"
# define WIN_X 2560 / 2
# define WIN_Y 1440 / 2
# define LEFTARROW 123
# define RIGHTARROW 124
# define DOWNARROW 125
# define UPARROW 126
# define PGUP 116
# define PGDOWN 121
# define KP_MINUS 78
# define KP_PLUS 69

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
	int		scale;
	int		scalebase;
}				t_info;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*image;
	t_info	info;
	t_map	map;
}				t_env;

void			ft_trace(t_point a, t_point b, t_env *e);
int				ft_checkmap(char ***map);
char			***ft_getmap(int fd);
t_point			**convert_map(char	***map, t_info info);
int				ft_doubletablen(char ***tab);
int				*get_map_dims(char ***map);
t_info			ft_get_info(char ***map);
int				ft_puterr(char *str);
int				change_info(t_info *info, int keycode);
#endif
