/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_fichero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:12:32 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/31 14:26:15 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rows(char *fichero)
{
	int	fd;
	int	y;

	fd = open(fichero, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd))
	{
		y++;
	}
	close(fd);
	return (y);
}

int	get_columns(char *fichero)
{
	int		fd;
	int		x;
	char	*str;

	x = 0;
	fd = open(fichero, O_RDONLY, 0);
	str = get_next_line(fd);
	x = contador_words(str, ' ');
	close(fd);
	return (x);
}

static void	rellenar_z(char *line, int *z)
{
	char	**str;
	int		i;

	str = ft_split(line, ' ');
	i = 0;
	while (str[i])
	{
		z[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

int	get_z(t_data *info, char *fichero)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	while (i < info->height)
	{
		info->z[i] = (int *)malloc(sizeof(int) * (info->width + 1));
		if (!info->z[i])
			return (0);
		i++;
	}
	fd = open(fichero, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rellenar_z(line, info->z[i]);
		free(line);
		i++;
	}
	info->z[i] = NULL;
	return (0);
}

int	leer_fichero(t_data *info, char *fichero)
{
	info->height = get_rows(fichero);
	info->width = get_columns(fichero);
	info->z = (int **)malloc(sizeof(int *) * (info->height + 1));
	if (!info->z)
		return (0);
	return (get_z(info, fichero));
}
