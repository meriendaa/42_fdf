#include "fdf.h"

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


void añadir2(st_fdf *info)
{
	info->z0 = info->z[(int)info->y0][(int)info->x0];
	info->z1 = info->z[(int)info->y1][(int)info->x1];
	info->color = (info->z0 || info->z1) ? 0xe80c0c : 0xffffff;
	info->zoom = 25;
	info->move_x = 250;
	info->move_y = 150;
	info->z_move = 1;
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
}
