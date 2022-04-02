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

void bresenham(st_fdf *info)
{
    int dx, dy, dec, x, y;

    dx = info->x1 - info->x0;  
    dy = info->y1 - info->y0;  
    x = info->x0;  
    y = info->y0;  
    dec = 2 * (dy - dx);

    while(x <= info->x1 || y < info->y1)  
    {  
        if(dec >= 0)  
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, x, y, info->color);  
            y++;
            dec = dec + 2 * (dy - dx); 
        }  
        else
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, x, y, info->color);    
            dec = dec + 2 * dy; 
        }  
        x++;
    }

}

void añadir(st_fdf *info, int num)
{
	if (num == 1)
	{
		info->x0 = info->x;
		info->y0 = info->y;
		info->x1 = info->x + 1;
		info->y1 = info->y;
	}
	if (num == 2)
	{
		info->x0 = info->x;
		info->y0 = info->y;
		info->x1 = info->x;
		info->y1 = info->y + 1;
	}
	info->z0 = info->z[(int)info->y0][(int)info->x0];
	info->z1 = info->z[(int)info->y1][(int)info->x1];
	info->color = (info->z0) ? 0xe80c0c : 0xffffff;

    info->x0 *= info->zoom;
	info->y0 *= info->zoom;
	info->x1 *= info->zoom;
	info->y1 *= info->zoom;
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

	info->zoom = 25;

	draw(info);
	mlx_loop(info->mlx_in);
	return (0);
}
