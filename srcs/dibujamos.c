/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dibujamos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:26:45 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/31 14:26:46 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float steps(float dx, float dy)
{
	if (dx < 0 && dy < 0)
	{
		if (-dx < -dy)
			return (-dy);
		return (-dx);
	}
	else if (dx < 0)
	{
		if (-dx < dy)
			return (dy);
		return (-dx);
	}
	else if (dy < 0)
	{
		if (-dy < dx)
			return (dx);
		return (-dy);
	}
	else{
		if (dx < dy)
			return (dy);
		return (dx);
	}
}

//ALGORITMO DONDE PONDREMOS LOS PIXELES
static void bresenham(st_fdf *info)
{
    float dx, dy, max;
    añadir2(info);
    dx = info->x1 - info->x0;  
    dy = info->y1 - info->y0;
    max = steps(dx, dy);

    dx /= max;
    dy /= max;

    while((int)(info->x1 - info->x0) != 0 || (int)(info->y1 - info->y0) != 0 )  
    {  
        mlx_pixel_put(info->mlx_in, info->mlx_win, (int)info->x0, (int)info->y0, info->color); 
        info->x0 += dx;
        info->y0 += dy;   
    }
}

int draw(st_fdf *info)
{
	info->y = 0;
	while (info->y < info->height)
	{
		info->x = 0;
		while(info->x < info->width)
		{
			if (info->x < info->width - 1)
			{
				añadir(info, 1);
				bresenham(info);
			}
			if (info->y < info->height - 1)
			{
				añadir(info, 2);
				bresenham(info);
			}
			info->x++;
		}
		info->y++;
	} 
	return (0);
} 

int ventana(st_fdf *info)
{
	info->mlx_in = mlx_init();
	if(!info->mlx_in)
		return (0);

	info->mlx_win = mlx_new_window(info->mlx_in, 1920, 1080, "Teodoro");
	if(!info->mlx_win)
		return (0);

	draw(info);
	mlx_loop(info->mlx_in);
	return (0);
}
