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


//FUNCION ISOMETRICA
static void isommetrica(st_fdf *info)
{
	int aux_x;
	int aux_y;

	aux_x = info->x0;
	aux_y = info->y0;
	info->x0 = (info->x0 - info->y0) * cos(0.8);
	info->y0 = (info->x0 + info->y0) * sin(0.8) - info->z0;
	aux_x = info->x1;
	aux_y = info->y1;
	info->x1 = (info->x1 - info->y1) * cos(0.8);
	info->y1 = (info->x1 + info->y1) * sin(0.8) - info->z1;
}

//ACTUALIZAMOS VALORES PARA HACER LUEGO EL ALGORITMO
static void añadir2(st_fdf *info)
{
	info->z0 = info->z[(int)info->y0][(int)info->x0];
	info->z1 = info->z[(int)info->y1][(int)info->x1];
	info->color = (info->z0) ? 0xe80c0c : 0xffffff;
    info->x0 *= info->zoom;
	info->y0 *= info->zoom;
	info->x1 *= info->zoom;
	info->y1 *= info->zoom;

	isommetrica(info);
	info->x0 += info->move_x;
	info->x1 += info->move_x;
	info->y0 += info->move_y;
	info->y1 += info->move_y;
}


//ALGORITMO DONDE PONDREMOS LOS PIXELES
static void bresenham(st_fdf *info)
{
    int dx, dy, dec;

	añadir2(info);
    dx = info->x1 - info->x0;  
    dy = info->y1 - info->y0;  
    dec = 2 * (dy - dx);

    while(info->y0 < info->y1 && info->x0 < info->x1 )  
    {  
        if(dec >= 0)  
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, info->x0, info->y0, info->color);  
            dec = dec + 2 * (dy - dx); 
            info->y0++;
            info->x0++;
          
        }  
        else
        {  
            mlx_pixel_put(info->mlx_in, info->mlx_win, info->x0, info->y0, info->color);    
            dec = dec + 2 * dy;	
           	info->x0++;
        }
     	  //info->x0++;
    }
}


static void añadir(st_fdf *info, int num)
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
	info->move_x = 250;
	info->move_y = 150;
	info->z_move = 1;
	draw(info);
	mlx_loop(info->mlx_in);
	return (0);
}
