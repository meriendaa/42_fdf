#include "fdf.h"

int	contador_words(char const *s, char c)
{
	int	i;
	int	init;
	int	numword;

	numword = 0;
	i = -1;
	init = -1;
	while (s[++i])
	{
		if (init == -1 && s[i] != c)
			init = 1;
		if (init != -1 && s[i] == c)
		{	
			numword += 1;
			init = -1;
		}
	}
	if (init == 1)
		++numword;
	return (numword);
}