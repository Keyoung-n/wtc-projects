
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strs[2];

	i = -1;
	strs[0] = dst;
	strs[1] = (char*)src;
	while (++i < n && strs[1])
		strs[0][i] = strs[1][i];
	return (dst);
}
