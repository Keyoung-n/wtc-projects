#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	if (!s || !f)
		return (NULL);
	dest = ft_strdup(s);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(dest[i]);
		i++;
	}
	return (dest);
}
