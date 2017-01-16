/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:07:35 by niragne           #+#    #+#             */
/*   Updated: 2017/01/16 05:32:32 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_trace(t_point a, t_point b, t_env *e) // Trace des segments
{
	static int color = 0xFF02;
	float dx;
	float dy;
	float l;
	int i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	l = sqrt(pow(b.x + b.y, 2));
	i = 0;
	while (i < l)
	{
		mlx_pixel_put(e->mlx, e->win, 
		a.x + ((dx / l) * i), 		
		a.y + ((dy / l) * i), 		
		color);
		i++;
	}
}

void	ft_wireframe(t_point **map, t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i]->x)
	{
		while (map[i][j].x)
		{
			if (map[i][j + 1].x)
				ft_trace(map[i][j], map[i][j + 1], e);
			if (map[i + 1][j].x)
				ft_trace(map[i][j], map[i + 1][j], e);
			j++;
		}
		j = 0;
		i++;
	}
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(int ac, char **av)
{
	int fd;
	char ***map;
	int i=0;
	int j=0;
	t_env e;
	int k=0;
	t_point		**salut;
	t_point a;
	t_point b;

	a = ft_newpoint(50,50,50);
	b = ft_newpoint(75,75,75);

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1080, 720, "banane");
	fd = open(av[1], O_RDONLY);
	map = ft_getmap(fd);
	while (map[i])
	{
		while (map[i][j])
		{
			printf("%s ", map[i][j]);
			j++;
		}
		j = 0;
		printf(" \n");
		i++;	
	}
	printf("BA\n");
	salut = convert_map(map, 50, 50, 50);
	//printf("SAUCISSE\n");
	//ft_wireframe(salut, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}