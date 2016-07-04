#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = ft_strdup(s);
	while (ptr[i])
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
