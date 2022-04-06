/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:26:00 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/31 14:26:02 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void destroy(st_fdf *info)
{
	int i;
	i = 0;
	mlx_destroy_window(info->mlx_in, info->mlx_win);
	while (i < info->height)
	{
		free(info->z[i]);
		i++;
	}
	free(info);
	exit(0);
}


static void restart(st_fdf *info)
{
	mlx_destroy_window(info->mlx_in, info->mlx_win);
	ventana(info);
}


int deal_key (int key, st_fdf *info)
{
	if (key == 126)
		info->z_move++;
	if (key == 125)
		info->z_move--;
	if (key == 0)
		info->move_x -= 10;
	if (key == 2)
		info->move_x += 10;
	if (key == 13)
		info->move_y -= 10;
	if (key == 1)
		info->move_y += 10;
	if (key == 14)
		info->zoom -= 2;
	if (key == 12)
		info->zoom += 2;
	if (key == 53)
		destroy(info);
	restart(info);
	return (0);
}

int init(st_fdf *info)
{
	info->mlx_in = mlx_init();
	if(!info->mlx_in)
		return (0);
	info->zoom = 20;
	info->move_x = 450;
	info->move_y = 150;
	info->z_move = 1;
	return (0);
}

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		write(1, "hola", 4);
	}
	st_fdf	*info = NULL;
	info = (st_fdf *)malloc(sizeof(st_fdf));
	leer_fichero(info, argv[1]);
	init(info);
	ventana(info);
	return (0);
}
