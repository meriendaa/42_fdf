#include "fdf.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main (int argc, char **argv)
{
	st_fdf	*info = NULL;
	
	info = (st_fdf *)malloc(sizeof(st_fdf));
	if (argc != 2)
	{
		ft_putstr("Error de argumentos");
		exit(1);
	}
	leer_fichero(info, argv[1]);
	printf("%d\n", info->x);
	printf("%d\n", info->y);
	return (0);
}
