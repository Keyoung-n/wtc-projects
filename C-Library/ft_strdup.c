#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc((sizeof(src) + 1) * sizeof(char));
	ft_strcpy(dest, src);
	return (dest);
}
