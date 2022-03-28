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

int get_witdh(char *fichero)
{
	int x;
	int fd;

	x = 0;

	fd = open(fichero, O_RDONLY, 0);
	while(get_next_line(fd))
		x++;
	close(fd);
	return (x);
}

int leer_fichero(st_fdf *info, char *fichero)
{
	info->x = get_witdh(fichero);
	printf("%d\n", info->x);
	//info->y = get_rows(fichero);
	return(0);
}