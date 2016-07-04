
#include "libft.h"

char	*ft_itoa(int n)
{
	char *p;

	p = ft_strnew(20) + 19;
	if (n >= 0 && p)
	{
		*--p = '0' + (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
	}
	else if (p)
	{
		*--p = '0' - (n % 10);
		n /= 10;
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
	return (p);
}
