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

#include "../minilibx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
# include <fcntl.h>


typedef struct st_fdf {
	int width;
	int height;
	int **z;
	void *mlx_in;
	void *mlx_win;
	int x0;
	int x1;
	int y0;
	int y1;
	int zoom;

	int x;
	int y;
	
}st_fdf;


int leer_fichero(st_fdf *info, char *fichero);
int	contador_words(char const *s, char c);
int ventana(st_fdf *info);

#endif