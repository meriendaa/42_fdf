/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:50:55 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/28 17:50:56 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef struct t_data {
	int		width;
	int		height;
	int		**z;
	void	*mlx_in;
	void	*mlx_win;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	zoom;
	int		x;
	int		y;
	float	z0;
	float	z1;
	int		color;
	float	move_x;
	float	move_y;
	float	z_move;

}t_data;

int		leer_fichero(t_data *info, char *fichero);
int		contador_words(char const *s, char c);
int		ventana(t_data *info);
void	introducir(t_data *info, int num);
void	introducir2(t_data *info);
int		controls(int key, t_data *info);
int		init(t_data *info);

#endif