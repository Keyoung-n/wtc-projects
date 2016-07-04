
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (char *)s;
}
