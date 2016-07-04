#include "libft.h"

char		*strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char*)s1);
	if (!n)
		return (NULL);
	while (*s1 != '\0' && n >= (size_t)ft_strlen(s2))
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (0);
}
