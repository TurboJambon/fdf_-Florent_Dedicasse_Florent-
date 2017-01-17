/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:29 by niragne           #+#    #+#             */
/*   Updated: 2017/01/17 02:27:37 by niragne          ###   ########.fr       */
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

}				t_env;

typedef struct s_map
{
	t_point	**map;
	int		x;
	int		y;

}				t_map;

int				ft_checkmap(char **str);
char			***ft_getmap(int fd);
t_point			**convert_map(char	***map, int x, int y, int inc, int mapx, int mapy);
int				ft_doubletablen(char ***tab);
int				*get_map_dims(char ***map);




#endif