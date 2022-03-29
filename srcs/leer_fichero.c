/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_fichero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:12:32 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/28 18:12:33 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_rows(char *fichero)
{
	int		fd;
	int		x;

	fd = open(fichero, O_RDONLY, 0);
	x = 0;
	while (get_next_line(fd))
	{
		x++;
	}
	close(fd);
	return (x);
}

int get_columns (char *fichero)
{
	int fd;
	int y;
	char *str;

	y = 0;
	fd = open(fichero, O_RDONLY, 0);
	str = get_next_line(fd);
	y = contador_words(str, ' ');
	close(fd);
	return (y);
}

//Faltara rellenar matriz con los numeros sera un **int
//En el fdf.c recorremos la matriz para ver que se haya rellenado bien
// Ya se dibujara chicos


int leer_fichero(st_fdf *info, char *fichero)
{
	info->x = get_rows(fichero);
	info->y = get_columns(fichero);
	return(0);
}