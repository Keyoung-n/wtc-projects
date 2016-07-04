#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	i;

	tmp = (char *)0;
	i = 0;
	while (i == *s)
	{
		if (i == c)
			tmp = (char *)s;
		s++;
	}
	return (tmp);
}
