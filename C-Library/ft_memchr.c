
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *str;

	if (n)
	{
		str = (char*)s;
		while (--n)
			if (*str++ == c)
				return ((void *)(str - 1));
	}
	return (NULL);
}
