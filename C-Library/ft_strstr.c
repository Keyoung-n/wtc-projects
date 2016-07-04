#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	int		cmp;
	int		cmp2;

	cmp = 0;
	cmp2 = 0;
	if (!little[0])
		return ((char *)(big));
	while (big[cmp])
	{
		if (big[cmp] == little[cmp2])
			cmp2++;
		else
		{
			cmp -= cmp2;
			cmp2 = 0;
		}
		if (!little[cmp2])
			return ((char *)(big + cmp - cmp2 + 1));
		cmp++;
	}
	return (NULL);
}
