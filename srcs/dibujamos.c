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

int ventana(st_fdf *info)
{
	info->mlx_in = mlx_init();
	if(!info->mlx_in)
		return (0);

	info->mlx_win = mlx_new_window(info->mlx_in, 1920, 1080, "Teodoro");
	if(!info->mlx_win)
		return (0);
	mlx_loop(info->mlx_in);
	return (0);
}
