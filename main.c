/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 02:06:39 by niragne           #+#    #+#             */
/*   Updated: 2017/01/11 00:51:20 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define WIN_X 2560
#define WIN_Y 1440 
#define NORME "non"

//validey = 9991


typedef struct s_env
{
	void *mlx;
	void *win;

}				t_env;

int	mlx_square(void* mlx, void* win, int x, int y, int x2, int y2, int stopX1, int stopX2, int stopY1, int stopY2, int color)
{
	int banane;
	int i = 0;

	banane = x;

	while (y < y2)
	{
		banane = x;
		while (banane < x2)
		{
			if ((banane < stopX1 || banane > stopX2 - 1) || (y < stopY1 || y > stopY2 - 1))
			{
				mlx_pixel_put(mlx, win, banane, y, color++);				
				i++;
			}
			banane++;
			color = (color * color) % 0xFFFFFF;
		}
		y++;
	}
	return (i);
}

void	mlx_la_cascade_toi_meme_tu_sais(void* mlx, void* win, int x, int y, int inc)
{
	//FUCK LA NORME
	int i;
	int color = 0x00000000;
	int dimX = x / inc;
	int dimY = y / inc;


	while (i < inc)
	{
		printf("%i...\n",i );
		//mlx_square(mlx, win, (i * dimX), (i * dimY), x, y, color);

		color += 0;
		i++;
	}
}

void	mlx_les_carres_en_carres(void* mlx, void* win, int x, int y, float inc)
{
	float i = 0;
	int color = 0x00000000;
	int dimX = x / inc;
	int dimY = y / inc;
	char	load[] = "[                                                  ]";
	int j = 1;
	int pix = 0;
	int pixmax = x * y;
	int flag = 0;

	while (i <= inc / 2)
	{
		while (j < (pix * 100) / (pixmax) / 2)
		{
			load[j] = '=';
			j++;
		}
		j = 1;
		printf ("\033[1A");
		printf ("\033[K");
		printf("%f%%%s %i pixels written.\n", (float)((float)pix / (float)pixmax) * 100, load, pix);
		pix += mlx_square(mlx, win, (i * dimX), (i * dimY), 
			x - (i * dimX), y - (i * dimY),((i + 1) * dimX),
			 x - ((i + 1) * dimX), ((i + 1) * dimY), y - ((i + 1) * dimY), color);
		if (color >= 0xFF)
			flag = 1;
		else if (color < 0)
			flag = 0;
		if (flag)
			color -= (0x0000001);
		else
			color += (0x0000003);

		i++;
	}
			printf ("\033[1A");
			printf ("\033[K");
			load[50] = '=';
			printf("%i%%%s Done ! %i pixels written.\n", 100, load, pix);
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 49)
		exit(0);
	return(0);
}

int main(int argc, char const **av)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "SALUT");
	mlx_les_carres_en_carres(e.mlx, e.win, WIN_X,WIN_Y, atoi(av[1]));
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return 0;
}