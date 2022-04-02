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

    dx = x1 - x0;  
    dy = y1 - y0;  
    x = x0;  
    y = y0;  
    dec = 2 * dy - dx;  
    while(x < x1)  
    {  
        if(dec >= 0)  
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, x, y, 0xffffff);  
            y++;  
            dec = dec + 2 * (dy - dx);  
        }  
        else  
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, x, y, 0xffffff);    
            dec = dec + 2 * dy;
        }  
        x++;  
    }  

}

void draw(st_fdf *info)
{
	info->y = 0;
	while ((int)info->y < info->height)
	{
		info->x = 0;
		while((int)info->x < info->width)
		{
			info->x++;
			//dos condiciones
			//+1 o +y guardando x0, y0, x1, y1 en info
		}
		info->y++;
	} 

}

int ventana(st_fdf *info)
{
	info->mlx_in = mlx_init();
	if(!info->mlx_in)
		return (0);

	info->mlx_win = mlx_new_window(info->mlx_in, 1920, 1080, "Teodoro");
	if(!info->mlx_win)
		return (0);

	info->zoom = 20;

	draw(info);
	mlx_loop(info->mlx_in);
	return (0);
}
