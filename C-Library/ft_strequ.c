#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (((unsigned char)s1[i]) == ((unsigned char)s2[i]))
		return (1);
	else
		return (0);
}
