/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:45:07 by dchirol           #+#    #+#             */
/*   Updated: 2017/06/04 13:14:33 by dchirol          ###   ########.fr       */
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
# define SQ_SIZE info.sq_size
# define ANGLE info.angle
# define FIRSTX info.firstx
# define FIRSTY info.firsty
# define ERR_WINDOW "window error\n"
# define ERR_FILE "file error\n"
# define ERR_MAP "map error\n"
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
# define S 1
# define D 2
# define A 0

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
	float	angle;
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
void			free_points(t_point **arr, int mapy);
void			free_map(char ***map, int mapy, int mapx);
void			free_double(char **tab, int mapy);
void			init_dims(int *dims, char ***map);
void			ft_puterr_exit(char *str);

#endif
