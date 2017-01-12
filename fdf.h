/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:29 by niragne           #+#    #+#             */
/*   Updated: 2017/01/12 20:36:35 by niragne          ###   ########.fr       */
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

int				ft_check_map(int fd);

typedef struct	s_env
{
	void *mlx;
	void *win;

}				t_env;

#endif