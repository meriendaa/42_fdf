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

static void	destroy(t_data *info)
{
	int	i;

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

static void	restart(t_data *info)
{
	mlx_destroy_window(info->mlx_in, info->mlx_win);
	ventana(info);
}

int	controls(int key, t_data *info)
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

int	init(t_data *info)
{
	info->mlx_in = mlx_init();
	if (!info->mlx_in)
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*info;

	info = (t_data *)malloc(sizeof(t_data));
	if (argc != 2)
		write(1, "Error", 4);
	leer_fichero (info, argv[1]);
	init (info);
	info->zoom = 20;
	info->move_x = 450;
	info->move_y = 150;
	info->z_move = 1;
	ventana (info);
	return (0);
}
